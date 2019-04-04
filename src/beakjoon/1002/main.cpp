#define LOCAL
#include <iostream>
#include <cmath>

using namespace std;

int TC;
int X1, Y1, R1, X2, Y2, R2;

int dist(const pair<int, int>& p1, const pair<int, int>& p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;

    return dx * dx + dy * dy;
}

int solve() {
    int d = dist({X1, Y1}, {X2, Y2});
    if (R1 > R2) 
        swap(R1, R2);
    int add = R1 + R2;
    add = add * add;
    int sub = R2 - R1;
    sub = sub * sub;
    if (add > d && sub < d) {
        return 2;
    } else if (add == d) {
        return 1;
    } else if (sub == d && d != 0) {
        return 1;
    } else if (add < d) {
        return 0;
    } else if (sub > d) {
        return 0;
    } else if (d == 0 && sub) {
        return 0;
    }

    return -1;
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &TC);

    while (TC--) {
        scanf("%d %d %d %d %d %d", &X1, &Y1, &R1, &X2, &Y2, &R2);
        
        int sol = solve();

        printf("%d\n", sol);
    }

    return 0;
}

