#define LOCAL 
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define IMPOSSIBLE 5
#define NOT_CHOICE 10

using namespace std;

int g[501][501];
int in[501];

int main(void) {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int TC; scanf("%d", &TC);
    
    while (TC--) {
        int N, M; scanf("%d", &N);
        vector<int> prev;
        queue<int> q;

        memset(g, 0, sizeof(g));
        memset(in, 0, sizeof(in));

        for (int i = 0; i < N; i++) {
            int X; scanf("%d", &X);

            for (int& item : prev) {
                in[X]++;
                g[item][X] = 1;
            }

            prev.push_back(X);
        }

        scanf("%d", &M);

        for (int i = 0; i < M; i++) {
            int X, Y; scanf("%d %d", &X, &Y);

            if (g[X][Y]) {
                in[Y]--;
                in[X]++;

                g[X][Y] = 0;
                g[Y][X] = 1;
            } else {
                in[X]--;
                in[Y]++;

                g[Y][X] = 0;
                g[X][Y] = 1;
            }
        }

        for (int i = 1; i <= N; i++)
            if (in[i] == 0)
                q.push(i);

        vector<int> result;
        bool certain = true;

        while (q.size()) {
            if (q.size() > 1) {
                certain = false;
                break;
            }

            int cur = q.front(); q.pop();

            result.push_back(cur);

            for (int i = 1; i <= N; i++) {
                if (g[cur][i] == 0) continue;

                in[i]--;

                if (in[i] == 0)
                    q.push(i);
            }
        }

        if (!certain)
            printf("?");
        else if (result.size() == N) {
            for (int& item : result) 
                printf("%d ", item);
        } else {
            printf("IMPOSSIBLE");
        }

        printf("\n");
    }

    return 0;
}
