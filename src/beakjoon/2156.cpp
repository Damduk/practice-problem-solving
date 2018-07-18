#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 10001;
const int NONE = -999999;

int arr[MAX];
int DP[MAX][2];
int n;

int dp(int pos, int con) {
    if (con > 2) return NONE;
    if (pos >= n) return 0;

    int& ret = DP[pos][con];
    if (ret != -1)
        return ret;
    
    return ret = max(dp(pos + 1, 1), arr[pos] + max(dp(pos + 1, con + 1), dp(pos + 2, 1)));
}

int solve() {
    memset(DP, -1, sizeof(DP));
    
    int a = dp(0, 1);
    int b = dp(1, 1);
    
    return max(a, b);
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("%d", solve());
}