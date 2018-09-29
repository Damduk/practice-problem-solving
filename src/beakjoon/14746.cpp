#define local
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

int N, M;
int C1, C2;
int in;

typedef pair<int, int> ii;

vector<ii> s;

int main(void) {
#ifdef local 
    freopen("14746.in.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &M);
    scanf("%d %d", &C1, &C2);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &in);

        s.push_back({in, 0});
    }

    for (int i = 1; i <= M; i++) {
        scanf("%d", &in);

        s.push_back({in, 1});
    }

    sort(s.begin(), s.end(), greater<pair<int, int>>());
   
    int minV = 1e9;
    int minCnt = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1].second == s[i].second) {
            continue;
        }

        int diff = abs(s[i - 1].first - s[i].first);
        if (minV > diff) {
            minV = diff;
            minCnt = 1;
        } else if (minV == diff) {
            minCnt++;
        }
    }

    int bonus = abs(C1 - C2);

    printf("%d %d\n", minV + bonus, minCnt);

    return 0;
}
