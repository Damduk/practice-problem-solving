#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int N, M;
int board[20][20];
int visited[20][20];
int d[4][2] = {
    { 1, 0 },
    { -1, 0 },
    { 0, 1 },
    { 0, -1 },
};

vector<int> virus;

int fIdx(int pos) {
    return pos / M;
}

int sIdx(int pos) {
    return pos % M;
}

int posFromIdx(int f, int s) {
    return ((f * M) + s);
}

int isIn(int f, int s) {
    return f >= 0 && f < N && s >= 0 && s < M;
}

// Return count of node that visited
int dfs(int pos) {
    int fi = fIdx(pos);
    int se = sIdx(pos);

    int result = 0;

    for (int i = 0; i < 4; i++) {
        int nextFi = fi + d[i][0];
        int nextSe = se + d[i][1];

        if (!isIn(nextFi, nextSe)) {
            continue;
        }
        
        if (board[nextFi][nextSe] != 0) {
            continue;
        }

        if (visited[nextFi][nextSe]) {
            continue;
        }

        visited[nextFi][nextSe] = 1;

        result += (1 + dfs(posFromIdx(nextFi, nextSe)));
    }

    return result;
}

int solve(int area) {
    memset(visited, 0, sizeof(visited));

    int result = area;
    for (auto& item : virus) {
        result -= dfs(item);    
    }

    return result;
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &M);
    
    int area = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 0) {
                area++;
            } else if (board[i][j] == 2) {
                virus.push_back(posFromIdx(i, j));
            }
        }
    }

    int len = N * M;
    int result = 0;
    for (int i = 0; i < len; i++) {
        int& a = board[fIdx(i)][sIdx(i)];
        if (a != 0) {
            continue;
        }

        a = 1;

        for (int j = i + 1; j < len; j++) {
            int& b = board[fIdx(j)][sIdx(j)];
            if (b != 0) {
                continue;
            }

            b = 1;

            for (int k = j + 1; k < len; k++) {
                int& c = board[fIdx(k)][sIdx(k)];
                if (c != 0) {
                    continue;
                }

                c = 1;

                result = max(result, solve(area - 3));

                c = 0;
            }

            b = 0;
        }

        a = 0;
    }

    printf("%d\n", result);

    return 0;
}
