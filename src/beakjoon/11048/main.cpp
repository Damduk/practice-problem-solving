#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int N, M;
int candy[1010][1010];
int visited[1010][1010];
int DP[1010][1010];
int dx[3] = { 1, 0, 1 };
int dy[3] = { 0, 1, 1 };

int isIn(int fi, int si) {
    return fi > 0 && fi <= N && si > 0 && si <= M;
}

int solve(int fi, int si) {
    if (!isIn(fi, si)) return 0;

    int& ref = DP[fi][si];
    if (ref != -1) {
        return ref;
    }

    visited[fi][si] = true;

    int result = 0;

    for (int i = 0; i < 3; i++) {
        int nfi = fi + dx[i];
        int nsi = si + dy[i];

        if (visited[nfi][nsi]) continue;

        result = max(result, solve(nfi, nsi));
    }

    visited[fi][si] = false;

    return ref = result + candy[fi][si];
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    memset(DP, -1, sizeof(DP));

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &candy[i][j]);
        }
    }

    int result = solve(1, 1);

    printf("%d\n", result);

    return 0;
}
