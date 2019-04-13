#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> T[100005];

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
   
    for (int i = 0; i < N; i++)
        scanf("%d %d", &T[i].first, &T[i].second);
    
    sort(T, T + N, [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) 
            return a.first < b.first;

        return a.second < b.second;    
    });

    int cur = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (cur <= T[i].first) {
            cur = T[i].second;
            ans++;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
