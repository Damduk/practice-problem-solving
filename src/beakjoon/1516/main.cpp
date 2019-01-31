#define LOCAL

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t[501];
int in[501];
int result[501];

vector<int> adj[501];

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int N; scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        int X;

        scanf("%d", &t[i]);

        while (scanf("%d", &X) && X != -1) {
            in[i]++;
            adj[X].push_back(i);
        }
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (in[i] == 0) {
            q.push(i);
            result[i] = t[i];
        }
    }

    while (q.size()) {
        int cur = q.front(); q.pop();
        
        for (int& next : adj[cur]) {
            int& nextIn = in[next];
             
            result[next] = max(result[next], result[cur] + t[next]);

            nextIn -= 1;

            if (nextIn == 0) {
                q.push(next);
                
            }
        }
    }

    for (int i = 1; i <= N; i++) 
        printf("%d\n", result[i]);

    return 0;
}
