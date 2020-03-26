#include <iostream>
#include <cstdio>
#include <cstring>
#define N_MAX 101
#define INF 2E8
using namespace std;

int N, M;
int dist[N_MAX + 5][N_MAX + 5];

int main(void) {
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist[i][j] = INF;
    
    for (int i = 0; i < M; i++) {
        int s, e, w; 
        scanf("%d %d %d", &s, &e, &w);
        dist[s][e] = min(dist[s][e], w);
    }
    
    for (int m = 1; m <= N; m++)
        for (int s = 1; s <= N; s++)
            for (int e = 1; e <= N; e++)
                dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", (i == j || dist[i][j] == INF) ? 0 : dist[i][j]);
        }
        
        printf("\n");
    }
    
    return 0;
}