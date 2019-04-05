#include <iostream>
#define MAX_N 1000
#define MAX_P 10000

using namespace std;

int N;
int P[MAX_P + 10];
int DP[MAX_P + 10];

int main(void) {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) 
        scanf("%d", &P[i]);

    DP[1] = P[1];

    for (int i = 2; i <= N; i++) {
        DP[i] = P[i];

        for (int j = 1; j < i; j++) {
            int diff = i - j;
            int val = DP[diff] + P[j];

            DP[i] = max(DP[i], val);
        }
    }

    printf("%d\n", DP[N]);

    return 0;
}
