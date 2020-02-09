#include <cstdio>
#define MAX 100

using namespace std;

int N, L;
int M[MAX + 5][MAX + 5];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

int max(int a, int b) {
	return a < b ? b : a;
}

int abs(int x) {
	return x < 0 ? -x : x;
}

int can(int x, int y, int h, int d) {
	int xout = (x + (L - 1) * dx[d]) >= N;
	int yout = (y + (L - 1) * dy[d]) >= N;
	if (xout || yout) {
		return false;
	}
	
	for (int i = 0; i < L - 1; i++) {
		x += dx[d];
		y += dy[d];
		
		if (h != M[y][x]) {
			return false;
		}
	}
	
	return true;
}

int enable(int x, int y, int d) {
	int basecase = (d == 0 && x >= N) || (d == 1 && y >= N);
	if (basecase) {
		return 1;
	}
	
	int res = 0;
	int nx = x + dx[d];
	int ny = y + dy[d];	
	if (M[ny][nx] == 0 || M[y][x] == M[ny][nx]) {
		res = max(res, enable(nx, ny, d));
	} else if (M[y][x] - M[ny][nx] == 1) {
		int nnx = nx + (dx[d] * L);
		int nny = ny + (dy[d] * L);
		int diff = M[y][x] - M[nny][nnx];
		
		if (can(nx, ny, M[ny][nx], d) && (M[nny][nnx] ==0 || (diff == 2 || diff == 1))) {
			res = max(res, enable(nnx, nny, d));
		}
	}
	
	if (can(x, y, M[y][x], d)) {
		int nnx = x + (dx[d] * L);
		int nny = y + (dy[d] * L);
		if (M[nny][nnx] == 0 || M[y][x] - M[nny][nnx] == -1) {
			res = max(res, enable(nnx, nny, d));
		}
	}
	
	return res;
}

int main(void) {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &M[i][j]);
	
	int res = 0;
	
	for (int i = 0; i < N; i++) {
		int subres = enable(0, i, 0);
		// printf("[%d, %d]: %d\n", 0, i, subres);
		res += subres;
	}
		
	for (int i = 0; i < N; i++) {
		int subres = enable(i, 0, 1);
		// printf("[%d, %d]: %d\n", i, 0, subres);
		res += subres;
	}
	
	printf("%d\n", res);
	
	return 0;
}