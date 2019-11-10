#define LOCAL
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAX_L = 305;

int L;
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int visited[MAX_L][MAX_L];

int isOut(const pii& cur) {
	return cur.first < 0 || cur.first >= L || cur.second < 0 || cur.second >= L;
}

int bfs(int initialState, const pii target, const pii cur) {
	queue<pair<int, pii>> q;

	q.push(make_pair(initialState, cur));

	while (q.size()) {
		const int state = q.front().first;
		const pii cur = q.front().second;
		
		q.pop();
		
		if (target.first == cur.first && target.second == cur.second) {
			return state;
		} 
		
		if (visited[cur.first][cur.second]) {
			continue;
		}

		visited[cur.first][cur.second] = true;

		for (int i = 0; i < 8; i++) {
			int nx = dx[i] + cur.first;
			int ny = dy[i] + cur.second;

			if (isOut(make_pair(nx, ny)) || visited[nx][ny]) {
				continue;
			}

			q.push(make_pair(state + 1, make_pair(nx, ny)));
		}
	}

	return -1;
}

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int TC; scanf("%d", &TC);

	while (TC--) {
		scanf("%d", &L);	

		pii src, dest;

		scanf("%d %d %d %d", &src.first, &src.second, &dest.first, &dest.second);

		memset(visited, 0, sizeof(visited));		

		const int ans = bfs(0, dest, src);
		
		printf("%d\n", ans);
	}

	return 0;
}
