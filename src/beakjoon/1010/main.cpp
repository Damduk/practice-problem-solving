#include <iostream>

using namespace std;

int TC;
int N, M;
int DP[35][35];

int main(void) {
    scanf("%d", &TC);
    
    for (int i = 1; i < 30; i++)
        DP[1][i] = i;

    for (int i = 2; i < 30; i++) {
        for (int j = i; j < 30; j++) {
            for (int k = j - 1; k >= i - 1; k--) {
                DP[i][j] += DP[i - 1][k];
            }
        }
    }

    while (TC--) {
        scanf("%d %d", &N, &M);
        printf("%d\n", DP[N][M]);
    }

    return 0;
}
