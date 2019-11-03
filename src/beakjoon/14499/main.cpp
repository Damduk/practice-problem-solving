#define LOCAL
#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

int N, M;
int X, Y;
int K;

int m[MAX][MAX];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int die[7];
int tmp[7];

void changeDie(int op) {
	memcpy(tmp, die, sizeof(die));

	if (op == 1) {
		die[1] = tmp[4];
		die[3] = tmp[1];
		die[4] = tmp[6];
		die[6] = tmp[3];
	} else if (op == 2) {
		die[1] = tmp[3];
		die[3] = tmp[6];
		die[4] = tmp[1];
		die[6] = tmp[4];
	} else if (op == 3) {
		die[1] = tmp[5];
		die[2] = tmp[1];
		die[5] = tmp[6];
		die[6] = tmp[2];
	} else if (op == 4) {
		die[1] = tmp[2];
		die[2] = tmp[6];
		die[5] = tmp[1];
		die[6] = tmp[5];
	}
}

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d %d %d %d", &N, &M, &Y, &X, &K);	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		int op; scanf("%d", &op);
		
		int nx = X + dx[op - 1];
		int ny = Y + dy[op - 1];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
			continue;
		}

		changeDie(op);

		const int& bottom = die[6];
		const int& val = m[ny][nx];
		if (val == 0) {
			m[ny][nx] = bottom;
		} else {
			die[6] = val;
			m[ny][nx] = 0;
		}	
		
		X = nx;
		Y = ny;
		const int top = die[1];

		printf("%d\n", top);
	}

	return 0;
}
