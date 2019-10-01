#define LOCAL
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

bool contain(pii p1, pii p2, int r) {
	int dx = p2.first - p1.first;
	int dy = p2.second - p1.second;
	int dist = (dx * dx) + (dy * dy);

	return (r * r) > dist;
}

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int TC; scanf("%d", &TC);

	while (TC--) {
		int x1, y1, x2, y2;
		int sol = 0;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x, y, r; scanf("%d %d %d", &x, &y, &r);

			bool p1 = contain({ x1, y1 }, { x, y }, r);
			bool p2 = contain({ x2, y2 }, { x, y }, r);

			if (p1 != p2) {
				sol++;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}
