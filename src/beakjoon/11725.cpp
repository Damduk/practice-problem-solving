#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

const int MAX = 100001;

vi adj[MAX];
int parent[MAX];
int N, A, B;

int main() {
    scanf("%d", &N);
    
    parent[1] = -1; 
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A, &B);
        
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    
    queue<int> q;
    
    q.push(1);
    
    while (q.size()) {
        int current = q.front(); q.pop();
        
        for (auto& child : adj[current]) {
            if (child == parent[current]) 
                continue;
            
            q.push(child);
            parent[child] = current;
        }
    }
   
    for (int i = 2; i <= N; i++)
        printf("%d\n", parent[i]);
}