#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAX = 501;
const int ADJ_MAX = 25001;
const string FAILED = "IMPOSSIBLE";

int arr[MAX];
int in[MAX];
int visited[MAX];
vector<int> adj[ADJ_MAX];

int n, m;

stack<int> topo_sort(const int& start) {
    queue<int> q;
    stack<int> result;
    
    q.push(start);
    
    while (q.size()) {
        const int& u = q.front();
        
        q.pop();
        //cout << u << endl;
        visited[u] = 1;
        
        for (auto& node : adj[u])
            in[node]--;
        
        if (q.empty()) {
            for (int i = n - 1; i >= 0; i--) {
                if (visited[arr[i]] || in[arr[i]] != 0)
                    continue;
                
                q.push(arr[i]);
                break;
            }
        }
            
        result.push(u);
    }
    
    return result;
}

void solve() {
    fill(visited, visited + n + 1, 0);
    
    int start = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (in[arr[i]] == 0) {
            start = arr[i];
            break;
        }
    }
    
    if (start == -1) {
        cout << FAILED << endl;
        return;
    }
    
    stack<int> result = topo_sort(start);
    
    if (result.size() != n)
        cout << FAILED;
    else {
        while (result.size()) {
            int top = result.top();
            
            result.pop();
            
            cout << top << " ";
        }
    }
    
    cout << "\n";
}

int main() {
    int TC;
    
    scanf("%d", &TC); 
    
    while (TC--) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        scanf("%d", &m);
        
        fill(in, in + n, 0);
        
        for (int i = 0; i < m; i++) {
            int a, b;
            
            scanf("%d %d", &a, &b);
            
            adj[b].push_back(a); 
            in[a]++;
        }
        
        solve();
    }
}