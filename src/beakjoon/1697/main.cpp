#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;

int N, K;
int visited[MAX + 10];
int dx[3] = {-1, 1, 0};
queue<pair<int, int>> q;

int solve(int n, int k) {
    if (n >= k) {
        return n - k;
    }

    visited[n] = true;
    q.push({n, 0});

    while (q.size()) {
        auto& p = q.front(); q.pop();
        int pos = p.first;
        int cnt = p.second;

        if (pos == k) {
            return cnt;
        }
    
        for (int i = 0; i < 3; i++) {
            int next = dx[i] == 0 ? pos * 2 : pos + dx[i];
            if (next < 0 || next > MAX) {
                continue;
            } else if (visited[next]) {
                continue;
            }

            q.push({next, cnt + 1});

            visited[next] = true;
        }
    }

    return -1;
}

int main(void) {
    int sol;

    scanf("%d %d", &N, &K);

    sol = solve(N, K);
   
    printf("%d\n", sol);

    return 0;
}

