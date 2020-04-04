#include <cstdio>
#include <cstring>
#define INF 2E9

int visited[1005][1005];
int A[1005][1005];
int DP[1005][1005][2];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int N, M;

int isOut(int x, int y) {
    return x < 1 || y < 1 || x > M || y > N;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int dfs(int x, int y, int a) {
    // base case
    if (x == M && y == N) {
        return 1;
    }
    
    int& ret = DP[x][y][a];
    if (ret != -1) {
        return ret;
    }
    
    visited[y][x] = 1;
    
    int res = INF;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isOut(nx, ny) || visited[ny][nx]) {
            continue;
        }
        
        int nv = A[ny][nx];
        if (nv == 0) {
            res = min(res, 1 + dfs(nx, ny, a));
        } else if (a == 1) {
            res = min(res, 1 + dfs(nx, ny, 0));
        }
    }
    
    visited[y][x] = 0;
    
    return ret = res;
}

int main(void) {
    memset(DP, -1, sizeof(DP));
    
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) 
            scanf("%1d", &A[i][j]);
    
    int res = dfs(1, 1, 1);
    
    printf("%d\n", res == INF ? -1 : res);
    
    return 0;
}