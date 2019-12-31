#define LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#define HOUSE 1
#define SHOP 2

using namespace std;

typedef vector<pair<int, int>> vii;

int N, M;
vii houses;
vii shops;
vector<bool> open;

int min(int& x, int& y) {
    return x < y ? x : y;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int isOpen(const int& x, const int& y) {
    for (int i = 0; i < shops.size(); i++) {
        if (shops[i].first == x && shops[i].second == y) {
            return open[i];
        }
    }
    return 0;
}

int dist(int x, int y) {
    int res = 2E9;
    for (auto& shop : shops) {
        if (!isOpen(shop.first, shop.second)) continue;

        int d = abs(x - shop.first) + abs(y - shop.second);

        res = min(res, d);
    }

    return res;
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp; scanf("%d", &tmp);
            if (tmp == SHOP) {
                shops.push_back({i, j});
                open.push_back(0);
            } else if (tmp == HOUSE) {
                houses.push_back({i, j});
            }
        }
    }

    fill(open.end() - M, open.end(), true);
   
    int res = 2E9;
    do {
        int sum = 0;
        for (auto& house : houses) 
            sum = sum + dist(house.first, house.second);
        res = min(res, sum);
    } while (next_permutation(open.begin(), open.end()));

    printf("%d\n", res);

    return 0;
}
