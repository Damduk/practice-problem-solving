#define LOCAL
#include <iostream>
#define MAX 100

using namespace std;

int N;
int M[105][105];
int visited[105][105];

void dfs(int source, int adj) {
    M[source][adj] = 1;
    visited[source][adj] = true;

    for (int i = 0; i < N; i++) {
        if (visited[source][i]) continue;
        if (M[adj][i] == 0) continue;

        dfs(source, i);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            if (M[i][j] == 0) continue;

            dfs(i, j);
        }
    }
}

int main(void) {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    solve();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }

        printf("\n");
    }

    return 0;
}
