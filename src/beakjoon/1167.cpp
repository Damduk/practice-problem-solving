#define LOCAL_TEST

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define V_MAX 100001

using namespace std;

vector<pair<int, int>> adj[V_MAX];
int visited[V_MAX];
int N;

int farNode;
int farDist;

int dfs(int node, int sum) {
    visited[node] = true;

    if (sum > farDist) {
        farNode = node;
        farDist = sum;
    }

    int result = 0;

    for (auto& pair : adj[node]) {
        int next = pair.first;
        int w = pair.second;

        if (visited[next]) {
            continue;
        }

        result = max(result, w + dfs(next, sum + w));
    }

    return result;
}

int main(void) {
#ifdef LOCAL_TEST 
    freopen("1167.txt", "r", stdin);
#endif
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        int node;

        scanf("%d", &node);

        while (1) {
            int next, w;

            scanf("%d", &next);

            if (next == -1) {
                break;
            }

            scanf("%d", &w);

            adj[node].push_back({next, w});
        }
    }

    dfs(1, 0);

    memset(visited, 0, sizeof(visited));

    int result = dfs(farNode, 0);

    printf("%d\n", result);

    return 0;
}
