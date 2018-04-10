#include <iostream>

using namespace std;

const int CITY_N = 101;
const int INF = 1000001;

int adj[CITY_N][CITY_N];

int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n; j++)
            adj[i][j] = INF;
    
    for (int i = 0; i < m; i++) {
        int start, end, cost;
        
        scanf("%d %d %d", &start, &end, &cost);
        
        adj[start][end] = min(adj[start][end], cost);
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || adj[i][j] == INF)
                printf("0 ");
            else
                printf("%d ", adj[i][j]);
        }
        
        printf("\n");
    }
}