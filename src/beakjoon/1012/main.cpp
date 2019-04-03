#define LOCAL
#include <iostream>
#include <cstring>

#define NONE 0
#define EXISTS 1
#define MAX 50

using namespace std;

pair<int, int> d[4] = {
    { -1, 0 }, // Left
    { 1, 0 }, // Right
    { 0, -1 }, // Down
    { 0, 1 }, // Up
};

int TC;
int M, N, K;
int X, Y;
int board[MAX + 10][MAX + 10];
int visited[MAX + 10][MAX + 10];

void init() {
    memset(board, NONE, sizeof(board));
    memset(visited, 0, sizeof(visited));
}

int isValidPos(const int& x, const int& y) {
    int ensureX = x >= 0 && x < M;
    int ensureY = y >= 0 && y < N;

    return ensureX && ensureY;
}

void dfs(const int& x, const int& y, const int& prevX, const int& prevY) {
    for (int i = 0; i < 4; i++) {
        int nextX = x + d[i].first;
        int nextY = y + d[i].second;
        int nextVal = board[nextX][nextY];
   
        if (nextX == x && nextY == y) {
            continue;
        }

        if (!isValidPos(nextX, nextY) || nextVal != EXISTS) {
            continue;
        }

        if (visited[nextX][nextY]) {
            continue;
        }

        visited[nextX][nextY] = 1;

        dfs(nextX, nextY, x, y);
    }
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &TC);

    while (TC--) {
        init();

        scanf("%d %d %d", &M, &N, &K);

        for (int i = 0; i < K; i++) {
            scanf("%d %d", &X, &Y);

            board[X][Y] = EXISTS;
        }

        int ans = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                const int x = i;
                const int y = j;
                const int val = board[x][y];

                if (val != EXISTS) {
                    continue;
                }

                if (visited[x][y]) {
                    continue;
                }
                
                visited[x][y] = 1;

                dfs(x, y, 1E9, 1E9);

                ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
