#include <iostream>
#include <vector>
#include <queue>
#define N_MAX 1005
#define INF 2E9

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int N, M;
int A, B;

vii adj[N_MAX];
int visited[N_MAX];

priority_queue<ii> pq;

int main(void) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int x, y, w; scanf("%d %d %d", &x, &y, &w);
        
        adj[x].push_back({y, w});
    }
    
    scanf("%d %d", &A, &B);
    
    pq.push({0, A});
    
    for (int i = 0; i < N_MAX; i++)
        visited[i] = INF;
    
    int res = -1;
    while (pq.size()) {
        ii t = pq.top(); pq.pop();
        int node = t.second;
        int w = -t.first;
        
        if (node == B) {
            res = w;
            break;
        }
        
        visited[node] = w;
        
        for (ii next : adj[node]) {
            int nextw = w + next.second;
            if (visited[next.first] > nextw)
                pq.push({ -nextw, next.first });
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}