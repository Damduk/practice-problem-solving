#include <cstdio>
#define MOD 15746

using namespace std;

int DP[1000005];

int main(void) {
    int N; scanf("%d", &N);

    DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= N; i++)
        DP[i] = ((DP[i - 2] + DP[i - 1]) % MOD) % MOD;

    printf("%d\n", DP[N]);

    return 0;
}
