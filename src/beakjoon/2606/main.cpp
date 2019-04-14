#define LOCAL
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adjList[101];

int visited[101];
int N, M;
int A, B;

int solve() {
    int result = 0;
    queue<int> q;

    q.push(1);
    visited[1] = true;

    while (q.size()) {
        int cur = q.front(); q.pop();

        for (auto& next : adjList[cur]) {
            if (visited[next]) {
                continue;
            }

            q.push(next);
            visited[next] = true;

            result++;
        }
    }

    return result;
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);

        adjList[A].push_back(B);
        adjList[B].push_back(A);
    }

    int sol = solve();

    printf("%d\n", sol);

    return 0;
}
