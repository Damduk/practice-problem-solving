#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int board[105][105];
pair<int, int> d[4] = {
    { -1, 0 }, // Left
    { 1, 0 }, // Right
    { 0, 1 }, // Up
    { 0, -1 }, // Down
};

int cache[105][105];

int bfs() {
    queue<pair<int, int>> q;
    q.push({1, 1});

    cache[1][1] = 1;

    while (q.size()) {
        int row = q.front().first;
        int column = q.front().second;

        q.pop();

        if (row == N && column == M)
            break;

        for (int i = 0; i < 4; i++) {
            int nextRow = row + d[i].second;
            int nextColumn = column + d[i].first;

            if (board[nextRow][nextColumn] != 1)
                continue;

            if (cache[nextRow][nextColumn] != -1)
                continue;

            cache[nextRow][nextColumn] = cache[row][column] + 1;
            q.push({nextRow, nextColumn});
        }
    }

    return cache[N][M];
}

int main(void) {
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &N, &M);
    
    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%1d", &board[i][j]);
    
    printf("%d\n", bfs());
    return 0;
}
