#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll dp[100001];
int coin[101];
int N, K;

int main() {
    scanf("%d %d", &N, &K);
    
    for (int i = 0; i < N; i++)
        scanf("%d", &coin[i]);

    dp[0] = 1;
    
    for (int i = 0; i < N; i++) 
        for (int j = 1; j <= K; j++) 
            if (j >= coin[i])
                dp[j] += dp[j - coin[i]];
    
    printf("%lld\n", dp[K]);
}