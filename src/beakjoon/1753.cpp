#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef struct edge {
    int to, cost;
    
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
    
    bool operator<(const edge& o) const {
        return cost > o.cost;
    }
} edge;

priority_queue<edge> q;
vector<edge> v[20001];
int dist[20001];
bool visited[20001];

const int INF = 1e9;

int main() {
    int n, m, s;
    
    scanf("%d %d %d", &n, &m, &s);
    
    for (int i = 0; i < m; i++) {
        int start, end, cost;
        
        scanf("%d %d %d", &start, &end, &cost);
        
        v[start].push_back(edge(end, cost));
    }
    
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    
    q.push(edge(s, 0));
    dist[s] = 0;
    
    while (!q.empty()) {
        edge cur = q.top(); q.pop();
        
        if (cur.cost > dist[cur.to]) 
            continue;
        
        for (auto& next : v[cur.to]) {
            if (dist[next.to] > cur.cost + next.cost) {
                dist[next.to] = cur.cost + next.cost;
                q.push(edge(next.to, dist[next.to]));
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("INF\n");
        else 
            printf("%d\n", dist[i]);
    }
}