#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int ans = -1, ansIdx;

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    for (int i = 0; i < 9; i++) {
        int input; scanf("%d", &input);

        ans = max(ans, input);
        if (ans == input) {
            ansIdx = i + 1;
        }
    }

    printf("%d\n%d\n", ans, ansIdx);

    return 0;
}