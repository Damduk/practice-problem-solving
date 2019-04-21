#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int N;

int cache[MAX];

int mPow(int n) {
    return n * n;
}

void init() {
    fill(cache, cache + MAX, 1E9);

    cache[0] = 0;
    cache[1] = 1;

    for (int i = 2; i <= MAX; i++) {
        int result = 0;

        for (int j = 1; j <= sqrt(i); j++) {
            result = 1 + cache[i - mPow(j)];
            cache[i] = min(cache[i], result);
        }
    }
}

int main(void) {
    init();

    scanf("%d", &N);
    printf("%d\n", cache[N]);

    return 0;
}
