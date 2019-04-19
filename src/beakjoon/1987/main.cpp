#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int R, C;
char board[30][30];
int visited[26];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int isIn(int a, int b) {
    return a > 0 && a <= R && b > 0 && b <= C;
}

int solve(int a, int b) {
    if (!isIn(a, b)) return 0;

    char v = board[a][b];

    visited[(int)v - (int)'A'] = true;

    int result = 0;

    for (int i = 0; i < 4; i++) {
        int nextF = a + dx[i];
        int nextS = b + dy[i];
        int nextV = board[nextF][nextS];

        if (visited[(int)nextV - (int)'A']) {
            continue;
        }

        result = max(result, solve(nextF, nextS));
    }

    visited[(int)v - (int)'A'] = false;

    return result + 1;
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &R, &C);

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    int result = solve(1, 1);
    
    printf("%d\n", result);

    return 0;
}
