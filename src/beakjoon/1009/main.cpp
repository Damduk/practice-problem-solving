#define LOCAL
#include <bits/stdc++.h>
#define MOD 10
using namespace std;

int TC;
int A, B;

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &TC);

    while (TC--) {
        scanf("%d %d", &A, &B);

        int result = A % MOD;

        for (int i = 1; i < B; i++) {
            result = (result * A) % MOD;
        }

        printf("%d\n", result == 0 ? 10 : result);
    }

    return 0;
}
