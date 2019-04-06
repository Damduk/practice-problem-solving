#define LOCAL
#include <iostream>
#include <cstring>

using namespace std;

int TC;
int N;
int A[2][100001];
int DP[2][100001];

int dp(int pos, int lv) {
    if (pos < 0 || pos >= N) return 0;

    int& result = DP[lv][pos];
    if (result != -1)
        return result;

    int next = 0;

    next = max(next, dp(pos + 1, !lv));
    next = max(next, dp(pos + 2, lv));
    next = max(next, dp(pos + 2, !lv));

    return result = A[lv][pos] + next;
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &TC);

    while (TC--) {
        memset(DP, -1, sizeof(DP));
        scanf("%d", &N);
        
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &A[i][j]);
        
        int result = 0;
        
        for (int i = 0; i < min(2, N); i++) {
            result = max(result, dp(i, 0));
            result = max(result, dp(i, 1));
        }

        printf("%d\n", result); 
    }

    return 0;
}
