#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

vector<int> adj[MAX + 3];
int visited[MAX + 3];

int N, M;
int A, B;

int dfs(int node, int depth) {
    if (node == B) {
        return depth;
    }
    
    visited[node] = true;
    
    int res = -1;
    for (int next : adj[node]) {
        if (visited[next]) {
            continue;
        }
        
        res = max(res, dfs(next, depth + 1));
    }
    
    return res;
}

int main(void) {
    scanf("%d %d %d %d", &N, &A, &B, &M);
    for (int i = 0; i < M; i++) {
        int x, y; scanf("%d %d", &x, &y);
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int res = dfs(A, 0);
    
    printf("%d\n", res);
}