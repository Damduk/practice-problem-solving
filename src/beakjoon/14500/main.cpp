#define LOCAL
#include <bits/stdc++.h>

using namespace std;

const int MAX = 501;
const int INF = -2E9;

int N, M;
int m[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int isOut(const int x, const int y) {
	return x < 0 || x >= M || y < 0 || y >= N;
}

int dfs(const int x, const int y, const int len) {
	if (len == 4) {
		return m[y][x];
	}

	visited[y][x] = true;

	int ret = INF;
	for (int i = 0; i < 4; i++) {
		const int nx = x + dx[i];
		const int ny = y + dy[i];
		if (visited[ny][nx] || isOut(nx, ny)) {
			continue;
		}

		ret = max(ret, m[y][x] + dfs(nx, ny, len + 1));	
	} 

	visited[y][x] = false;

	return ret;
}

int handleException(const int x, const int y) {
	int mv = -INF;
	int sum = m[y][x];
	int cnt = 0;	

	for (int i = 0; i < 4; i++) {
		const int nx = x + dx[i];
		const int ny = y + dy[i];

		if (isOut(nx, ny)) continue;

		mv = min(mv, m[ny][nx]);
		sum += m[ny][nx];
		cnt++;
	}

	if (cnt == 4)
		sum -= mv;

	return sum; 
}

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			scanf("%d", &m[i][j]);

	int sol = INF;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			sol = max(sol, dfs(x, y, 1));
			sol = max(sol, handleException(x, y));
		}
	}

	printf("%d\n", sol);

	return 0;
}
