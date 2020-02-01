#define LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#define ALIVE 1
#define ATTACKED 2
 
using namespace std;
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
 
int N, M, D;
vii bow;
viii enemy;
ii pivot;
 
const int INF = -2E9;

int abs(int x) {
	return x < 0 ? -x : x;
}
 
int dist(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}
 
int priority(iii a, iii b) {
	int d1 = dist(pivot.second, pivot.first, a.second.second, a.second.first);
	int d2 = dist(pivot.second, pivot.first, b.second.second, b.second.first);
	if (d1 != d2) {
		return d1 < d2;
	}
 
	return a.second.first < b.second.first;
}
 
void attack(viii& e) {
	for (auto b : bow) {
		pivot = b;
 
		sort(e.begin(), e.end(), priority);
 
		for (auto& en : e) {
			auto enPos = en.second;
			int d = dist(b.second, b.first, enPos.second, enPos.first);
			if (D >= d) {
				en.first = ATTACKED;
				break;
			}
		}
	}
}
 
int update(viii& e) {
	viii copy = e;
 
	int res = 0;
	for (auto& item : copy) {
		e.erase(e.begin());
		if (item.first == ATTACKED) {
			res++;
			continue;
		}
 
		item.second.second++;
		if (item.second.second >= N) {
			continue;
		}
 
		e.push_back(item);
	}
 
	return res;
}
 
int simulate() {
	viii copy = enemy;
 
	int res = 0;
	while (copy.size() > 0) {
		attack(copy);
		res = res + update(copy);
	}
 
	return res;
}
 
int backtracking(int select) {
	int res = -1;
	bow.push_back({select, N});
 
	if (bow.size() > 2) {
		res = simulate();
	} else {
		for (int next = select + 1; next < M; next++)
			res = max(res, backtracking(next));
	}
 
	bow.pop_back();
	return res;
}
 
int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d %d", &N, &M, &D);
	for (int i = 0; i < N; i++) { // Y
		for (int j = 0; j < M; j++) { // X
			int tmp; scanf("%d", &tmp);
			if (tmp == 1) {
				// printf("%d, %d\n", j + 1, i + 1);
				enemy.push_back({ALIVE, {j, i}});
			}
		}
	}
 
	int res = INF;
	for (int i = 0; i < M; i++) {
		res = max(res, backtracking(i));
	}
 
	printf("%d\n", res);
 
	return 0;
}