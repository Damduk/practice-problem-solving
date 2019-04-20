#include <bits/stdc++.h>
using namespace std;

int N;
int A, B;

int main(void) {
    A = 1000005;
    B = -1000005;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int tmp; scanf("%d", &tmp);

        A = min(A, tmp);
        B = max(B, tmp);
    }

    printf("%d %d\n", A, B);

    return 0;
}
