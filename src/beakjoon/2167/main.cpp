#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[310][310];
int K;
int I, J, X, Y;

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%d", &arr[i][j]);

    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        int result = 0;

        scanf("%d %d %d %d", &I, &J, &X, &Y);

        for (int y = J; y <= Y; y++) {
            for (int x = I; x <= X; x++) {
                result += arr[x][y];
            }
        }

        printf("%d\n", result);
    }
    return 0;
}
