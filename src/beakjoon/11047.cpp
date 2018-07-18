#include <iostream>
#include <cstring>

using namespace std;

const int N_MAX = 10;

int n, k;
int coin[N_MAX];

int get_focus(const int& k) {
    int result = 0;
    
    for (int i = 0; i < n; i++) 
        if (coin[i] <= k)
            result = max(result, coin[i]);
    
    return result;
}

int main() {
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++) 
        scanf("%d", &coin[i]);
    
    int cnt = 0;  
    while (k != 0) {
        int focus = get_focus(k);
        
        k -= focus;
        cnt += 1;
    }
    
    printf("%d\n", cnt);
}