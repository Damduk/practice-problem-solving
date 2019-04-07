#include <iostream>
#define MOD 10007

using namespace std;

int N;
int A[10];
int DP[1001][10];

int solve() {
    for (int i = 0; i < 10; i++) 
        DP[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                DP[i][j] = (DP[i][j] + DP[i - 1][k]) % MOD;
            }
        }
    }

    int result = 0;

    for (int i = 0; i < 10; i++)
        result = (result + DP[N][i]) % MOD;

    return result;
}

int main(void) {
    scanf("%d", &N);
    printf("%d\n", solve());

    return 0;
}
