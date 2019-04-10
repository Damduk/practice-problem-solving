#include <iostream>
#include <vector>
#include <algorithm>
#define ON 1
#define OFF 0

using namespace std;

int d[4][2] = {{ -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 }};
int board[110][110];
int visited[110][110];
int M, N, K;
int X1, X2, Y1, Y2;
vector<int> area;

int setOn(int x1, int y1, int x2, int y2) {
    for (int i = y1; i < y2; i++) 
        for (int j = x1; j < x2; j++)
            board[i][j] = ON;
}

int isValid(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

int getArea(int x, int y) {
    if (!isValid(x, y)) return 0;
    if (visited[x][y]) return 0;
    if (board[x][y] == ON) return 0;

    visited[x][y] = 1;

    int result = 1;
    for (int i = 0; i < 4; i++)
        result += getArea(x + d[i][0], y + d[i][1]);

    return result;
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int v = getArea(j, i);
            if (v > 0)
                area.push_back(v);
        }
    }

    sort(area.begin(), area.end());
}

int main(void) {
    scanf("%d %d %d", &M, &N, &K);

    for (int i = 0; i < K; i++) {
        scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
        setOn(X1, Y1, X2, Y2);
    }

    solve();

    printf("%d\n", area.size());
    for (int& item : area)
        printf("%d ", item);

    return 0;
}
