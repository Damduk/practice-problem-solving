#define LOCAL
#include <bits/stdc++.h>
#define MAX 5

using namespace std;

int mPow(int n) {
    return n * n;
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int tmp, sum = 0;
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &tmp);

        sum += mPow(tmp);
    }

    printf("%d\n", sum % 10);

    return 0;
}
