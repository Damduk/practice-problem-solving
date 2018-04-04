#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N_MAX = 1001;
const int K_MAX = 100001;

int memo[N_MAX];
int times[N_MAX];

int n, k, w;

int dp(const int& node, const vector<int> adj[K_MAX]) {
    int& ret = memo[node];
    if (ret != -1)
        return ret;
     
    int result = 0;
    
    for (auto& next : adj[node]) 
        result = max(result, dp(next, adj));
        
    return ret = times[node] + result;
}

int solve(const int& end, const vector<int> adj[K_MAX]) {
    memset(memo, -1, sizeof(memo));
    
    return dp(end, adj);
}

int main() {
    int T;
    
    scanf("%d", &T);
    
    while (T--) {
        vector<int> adj[K_MAX];
        
        scanf("%d %d", &n, &k);
        
        for (int i = 1; i <= n; i++)
            scanf("%d", &times[i]);
        
        for (int i = 1; i <= k; i++) {
            int x, y;
            
            scanf("%d %d", &x, &y);
            
            adj[x].push_back(y);
        }
        
        scanf("%d", &w);    
        printf("%d\n", solve(1, adj));
    }
}