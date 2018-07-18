#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Edge {
    int a, b, cost;
    
    bool operator<(const Edge& edge) const {
        return edge.cost > cost;
    }
} Edge;

const int V_MAX = 10001;

vector<Edge> edges;
int parent[V_MAX];

int find(int cur) {
    if (parent[cur] == cur)
        return cur;
    
    return parent[cur] = find(parent[cur]);
}

int merge(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a == b) 
        return 0;
    
    parent[b] = a;
    
    return 1;
}

int main() {
    int V, E; scanf("%d %d", &V, &E);
    
    for (int i = 1; i <= V; i++)
        parent[i] = i;
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        
        scanf("%d %d %d", &a, &b, &c);
        
        edges.push_back({a, b, c});        
    }
    
    sort(edges.begin(), edges.end());
    
    int result = 0, cnt = 0;    
    for (auto& item : edges) {
        if (merge(item.a, item.b)) {
            result += item.cost;
            cnt++;
            
            if (cnt == V - 1)
                break;
        }
    }
    
    printf("%d", result);
}