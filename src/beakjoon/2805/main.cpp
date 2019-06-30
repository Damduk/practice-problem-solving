#define LOCAL
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll tree[1000001];

ll N, M;
ll MAX;

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%lld %lld", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &tree[i]);

        MAX = max(MAX, tree[i]);
    }

    ll left = 0, right = MAX;
    ll ans = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll total = 0;

        for (int i = 0; i < N; i++) 
            if (mid < tree[i])
                total += tree[i] - mid;

        if (total >= M) {
            ans = max(ans, mid);

            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
