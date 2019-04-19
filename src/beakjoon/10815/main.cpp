#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int N, M;
set<int> S;

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int tmp; scanf("%d", &tmp);
        S.insert(tmp);
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int target; scanf("%d", &target);
        bool exists = S.find(target) != S.end();
        
        printf("%d ", exists);
    }

    return 0;
}
