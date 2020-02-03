#include <cstdio>
#define INF 2E9
#define MAX 10

using namespace std;

int remain;
int res = INF, subres;
int M[MAX + 3][MAX + 3];
int select[6];

bool valid(int x, int y, int lv) {
	for (int i = 0; i < lv; i++)
		for (int j = 0; j < lv; j++)
			if (M[y + i][x + j] == 0)
				return false;
	
	return true;
}

void fill(int x, int y, int lv, int to) {
	for (int i = 0; i < lv; i++)
		for (int j = 0; j < lv; j++)
			M[y +i][x + j] = to;
}

int min(int a, int b) {
	return a < b ? a : b;
}

void backtracking(int idx) {
	if (res < subres) return;
	if (idx == 100) {
		res = min(res, subres);
		return;
	}
	
	int row = idx / 10;
	int col = idx % 10;
	if (M[row][col] == 1) {
		for (int lv = 1; lv <= 5; lv++) {
			if (select[lv] >= 5) {
				continue;
			}
			
			if (!valid(col, row, lv)) {
				continue;
			}
			
			fill(col, row, lv, 0);
			remain -= lv * lv;
			select[lv]++;
			subres++;
			
			backtracking(idx + 1);
			
			subres--;
			select[lv]--;
			remain += lv * lv;
			fill(col, row, lv, 1);
		}
	} else {
		backtracking(idx + 1);
	}
}

int main(void) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			scanf("%d", &M[i][j]);
			if (M[i][j] == 1) {
				remain++;
			}
		}
	}	
	
	backtracking(0);
	
	printf("%d\n", res == INF ? -1 : res);
	
	return 0;
}