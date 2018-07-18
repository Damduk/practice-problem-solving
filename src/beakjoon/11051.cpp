#include <cstdio>
#include <cstring>

#define N_MAX 1001
#define K_MAX 1001
#define MOD 10007

int cache[N_MAX][K_MAX];

int solve(const int& n, const int& k) {
    if (n == k || k == 0)
        return 1;
    
    int& ret = cache[n][k];
    if (ret != -1)
        return ret;
        
    return ret = (solve(n - 1, k - 1) + solve(n - 1, k)) % MOD;
}

int main() {
    int n, k;
    
    memset(cache, -1, sizeof(cache));
    
    scanf("%d %d", &n, &k);
    printf("%d\n", solve(n, k));
}