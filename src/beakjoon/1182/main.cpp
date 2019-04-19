#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int N, S;
vector<int> A;

int backTrack(int node, int remain) {
    if (node >= N) return 0;

    int result = 0;
    if (remain == 0) {
        result++;
    }

    for (int i = node + 1; i < N; i++) {
        result += backTrack(i, remain - A[i]);
    }

    return result;
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &S);

    A = vector<int>(N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    
    int result = 0;

    for (int i = 0; i < N; i++)
        result += backTrack(i, S - A[i]);

    printf("%d\n", result);

    return 0;
}
