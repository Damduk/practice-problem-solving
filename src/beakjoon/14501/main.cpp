#define LOCAL
#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int N;
int T[MAX];
int P[MAX];
int DP[MAX];

int dp(int n) {
    if (n > N) 
        return 0; 

    int& ret = DP[n];
    if (ret != -1) 
        return ret;

    int choice = 0;
    int next = n + T[n];
    if (next - 1 <= N)
        choice = P[n] + dp(next);

    int notchoice = 0;
    if (n + 1 <= N)
        notchoice += dp(n + 1);

    return ret = max(choice, notchoice);
}

int solve() {
    int result = 0;

    for (int i = 1; i <= N; i++) 
        result = max(result, dp(i));
        
    return result;
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    memset(DP, -1, sizeof(DP));

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }

    int result = solve();

    printf("%d\n", result);

    return 0;
}
