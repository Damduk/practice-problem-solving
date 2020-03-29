#include <cstdio>
#include <cstring>
#define MOD 1000000000

using namespace std;

typedef long long ll;

int N, K;
ll cache[205][205];

ll backtracking(ll val, int sz) {
    if (val > 200 || sz == K) {
        return N == val;
    }

    ll& ret = cache[val][sz];
    if (ret != -1) {
        return ret;
    }
    
    ll res = 0;
    for (int i = 0; i <= N; i++)
        res += backtracking(val + i, sz + 1) % MOD;
    
    return ret = res % MOD;
}

int main(void) {
    memset(cache, -1, sizeof(cache));
    
    scanf("%d %d", &N, &K);
    printf("%lld\n", backtracking(0, 0));
    return 0;
}