#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int A[105][105];
vector<int> rect;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1};

int isOut(int x, int y) {
    return x < 0 || y < 0 || x >= N || y >= M;
}

int dfs(int x, int y) {
    A[y][x] = 2;
    
    int res = 1; 
    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (isOut(nextx, nexty) || A[nexty][nextx] > 0) {
            continue;
        }
        
        res += dfs(nextx, nexty); 
    } 
    return res;
}

void cover(int x1, int y1, int x2, int y2) {
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            A[i][j] = 1;
        }
    }
}

int main() {
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        cover(x1, y1, x2, y2);
    }
 
    int res = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > 0) {
                continue;
            }
            
            res++;
            rect.push_back(dfs(j, i));
        }
    }
  
    sort(rect.begin(), rect.end());
    
    printf("%d\n", res);
    for (auto item : rect) {
        printf("%d ", item);
    }
	return 0;
}