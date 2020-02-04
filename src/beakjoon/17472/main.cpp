#include <cstdio>
#include <vector>
#define INF 2E9

using namespace std;

int N, M;
int A[12][12];
int gids[12][12], gid;
int res = INF, subres;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

bool isOut(int x, int y) {
	return x < 0 || y < 0 || x >= M || y >= N;
}

int fill(int x, int y , int nextx, int nexty, int to) {
	int res = 0;
	if (x == nextx) 
		for (int i = y + 1; i < nexty; i++, res++)
			A[i][x] += to;
	else
		for (int i = x + 1; i < nextx; i++,res++)
			A[y][i] += to;
			
	return res;
}

int min(int x, int y) {
	return x < y ? x : y;
}

int isSameSet(int a, int b, vector<int>& pids) {
	return pids[a] == pids[b];
}

void unionSet(int a, int b, vector<int>& pids) {
	if (isSameSet(a, b, pids)) return;
	
	int left, right;
	if (a < b) {
		left = a;
		right = b;
	} else {
		left = b;
		right = a;
	}
	
	for (int i = 1; i <= 6; i++)
		if (pids[i] == left)
			pids[i] = right;
}

void backtracking(int grid, vector<int> pids) {
	if (gid == 1) {
		res = min(res, subres);
	}
	
	if (grid == 100 || res < subres) {
		return;
	}
	
	int row = grid / 10;
	int col = grid % 10;
	
	int v = A[row][col];
	if (v == 1) {
		int pid = pids[gids[row][col]];
		
		for (int i = 0; i < 2; i++) {
			int nextr = row + dy[i];
			int nextc = col + dx[i];
			int dist = 1;
			
			while (!isOut(nextc, nextr) && A[nextr][nextc] != 1) {
				nextr = nextr + dy[i];
				nextc = nextc + dx[i];
				dist++;
			}
			
			if (isOut(nextc, nextr) || A[nextr][nextc] != 1 || dist < 3) {
				continue;
			}
			
			int nextgid = gids[nextr][nextc];
			int nextpid = pids[nextgid];
			if (pid == nextpid) {
				continue;
			}
			
			vector<int> affect = pids;
			unionSet(pid, nextpid, affect);
			subres += fill(col, row, nextc, nextr, 2);
			gid--;
			
			backtracking(0, affect);
			
			subres -= fill(col, row, nextc, nextr, -2);
			gid++;
		}
	}
	
	backtracking(grid + 1, pids);
}

void setGid(int x, int y, int gid) {
	gids[y][x] = gid;
	
	for (int i = 0; i < 4; i++) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if (isOut(nextx, nexty)) {
			continue;
		}
		
		if (A[nexty][nextx] == 0 || gids[nexty][nextx] != 0) {
			continue;
		}
		
		setGid(nextx, nexty, gid);
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &A[i][j]);
			
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (A[i][j] == 1 && gids[i][j] == 0)
				setGid(j, i, ++gid);
	
	vector<int> pids;
	for (int i = 0; i <= 6; i++)
		pids.push_back(i);
		
	backtracking(0, pids);
	
	printf("%d\n", res == INF ? -1 : res);
	return 0;
}