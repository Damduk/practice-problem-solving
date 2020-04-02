#include <iostream>
#include <queue>
#define INF 2E9

using namespace std;

int N, M;
char A[12][12];
int visited[12][12][12][12];

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

typedef struct node {
    int rx, ry, bx, by, depth;
} Node;

queue<Node> q;

void move(int &x, int &y, int &c, int dx, int dy) {
    while (A[x+dx][y+dy] != '#' && A[x][y] != 'O') {
        x += dx;
        y += dy;
        c += 1;
    }
}

int bfs() {
    while (q.size()) {
        Node node = q.front(); q.pop();
        int rx = node.rx, ry = node.ry;
        int bx = node.bx, by = node.by;
        int depth = node.depth;
        if (depth >= 10) {
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int rc = 0, bc = 0, ndepth = depth + 1;
            
            move(nrx, nry, rc, dx[i], dy[i]);
            move(nbx, nby, bc, dx[i], dy[i]);
            
            if (A[nbx][nby] == 'O') continue;
            if (A[nrx][nry] == 'O') return ndepth;
            
            if (nrx == nbx && nry == nby) {
                if (rc > bc) nrx -= dx[i], nry -= dy[i];
                else nbx -= dx[i], nby -= dy[i];
            }
            
            if (visited[nrx][nry][nbx][nby]) continue;
            
            visited[nrx][nry][nbx][nby] = 1;
            
            q.push({nrx, nry, nbx, nby, ndepth});
        }
    }
    
    return -1;
}

int main(void) {
    scanf("%d %d", &N, &M);
    
    int rx = 0, ry = 0, bx = 0, by = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf(" %c", &A[i][j]);
            if (A[i][j] == 'R') rx = i, ry = j;
            else if (A[i][j] == 'B') bx = i, by = j;
        }
    }
    
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = 1;
    
    printf("%d\n", bfs());
    
    return 0;
}