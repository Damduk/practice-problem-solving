#include <iostream>
#include <queue>
#define INF 2E9
using namespace std;

int N, R, C;
int sz;

int dx[] = { 0, 1, 0, 1 };
int dy[] = { 0, 0, 1, 1 };
int cnt = 0;
int res = INF;

void divide(int x, int y, int sz) {
    if (res != INF) return;
    
    if (sz > 1) {
        for (int i = 0; i < 4; i++)
            divide(sz * dx[i] + x, sz * dy[i] + y, sz / 2);
    } else {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx == C && ny == R) {
                res = cnt;
                return;
            }

            cnt++;
        }   
    }
}

int main(void) {
    scanf("%d %d %d", &N, &R, &C);
    
    sz = 2;
    for (int i = 0; i < N - 1; i++)
        sz = sz + sz;

    divide(0, 0, sz);
    
    printf("%d\n", res);
}