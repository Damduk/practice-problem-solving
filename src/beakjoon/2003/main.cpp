#include <cstdio>
#define MAX 10000

typedef long long ll;

ll psum[MAX + 3];

ll query(int i, int j) {
    return psum[j] - psum[i];
}

int main(void) {
    int N, M; scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &psum[i]);
        if (i > 0)
            psum[i] += psum[i - 1];
    }
    
    int res = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            ll s = query(i, j);
            if (s == M) {
                res++;
                break;
            } else if (s > M) {
                break;
            }
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}