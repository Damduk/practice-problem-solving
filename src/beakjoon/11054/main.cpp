#define LOCAL
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int A[1005];
int DP[1005][2];

int max(int a, int b) { 
    return a > b ? a : b;
}

int solve(int p, bool descendant) {
    if (p >= N) return 0;
 
    int& ret = DP[p][descendant];
    if (ret != -1) return ret;

    int cur = A[p];
    int res = 0;
    for (int i = p + 1; i < N; i++) {
        int next = A[i];

        if (cur == next) continue;
        if (descendant && cur < next) continue;

        res = max(res, solve(i, cur > next));
    }

    return ret = 1 + res;
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    memset(DP, -1, sizeof(DP));

    int res = -1;
    for (int i = 0; i < N; i++)
        res = max(res, solve(i, false));

    printf("%d\n", res);
    return 0;
}
