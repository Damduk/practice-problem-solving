#include <iostream>
#include <cstring>

using namespace std;

const int N_MAX = 100;
const int K_MAX = 10001;

int n, k;
int coin[N_MAX];

int DP[K_MAX];

int solve(const int& k) {
    if (k < 0) return K_MAX;
    if (k == 0) return 1;
    
    int& ret = DP[k];
    if (ret != -1)
        return ret;
    
    int result = K_MAX;
    for (int i = 0; i < n; i++)
        result = min(result, solve(k - coin[i]));
    
    return ret = 1 + result;
}

int main() {
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++) 
        scanf("%d", &coin[i]);
    
    memset(DP, -1, sizeof(DP));
    
    int result = K_MAX;
    for (int i = 0; i < n; i++)
        result = min(result, solve(k - coin[i]));
    
    printf("%d\n", result != K_MAX ? result : -1);
}