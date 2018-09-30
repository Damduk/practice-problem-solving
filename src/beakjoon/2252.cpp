#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adjList[32005];
queue<int> pq;
int indegree[32005];

int N, M;
int A, B;

int main(void) {
#ifdef local
    freopen("2252.in.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &M);    

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        
        indegree[B]++;

        adjList[A].push_back(B);
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    while (pq.size()) {
        auto top = pq.front(); pq.pop();

        for (auto& item : adjList[top]) {
            indegree[item]--;

            if (indegree[item] == 0) {
                pq.push(item);
            }
        }

        printf("%d ", top);
    }

    return 0;
}
