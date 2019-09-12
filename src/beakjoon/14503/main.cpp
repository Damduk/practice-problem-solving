#include <bits/stdc++.h>

using namespace std;

const int NONE = 0, BLOCK = -1, CLEAN = 1;

int N, M, R, C, D;
int board[54][54];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int left(int d) {
	return --d < 0 ? 3 : d;
}

int clean(int x, int y, int d) {
	int result = 0;
	
	if (board[x][y] == NONE) {
		board[x][y] = CLEAN;
		result++;
	} 

	int nextd = d;
	for (int i = 0; i < 4; i++) {
		nextd = left(nextd);
		int nextx = x + dx[nextd];
		int nexty = y + dy[nextd];
		
		if (board[nextx][nexty] == NONE) {
			return clean(nextx, nexty, nextd) + result;
		}		
	}
	
	int nextx = x + (-1 * dx[d]);
	int nexty = y + (-1 * dy[d]);
	if (board[nextx][nexty] != BLOCK) {
		return clean(nextx, nexty, d) + result;
	}
	
	return result;
}

int main(void) {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &R, &C, &D);
	
	memset(board, BLOCK, sizeof(board));
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int in; scanf("%d", &in);
			
			board[j][i] = in == NONE ? NONE : BLOCK;
		}
	}
	
	printf("%d\n", clean(C + 1, R + 1, D));
	
	return 0;
}
