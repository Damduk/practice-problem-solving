#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 50
#define INF 2E9

using namespace std;

typedef pair<int, pair<int, int>> iii;

int N, M, K;
int A[MAX + 5][MAX + 5], B[MAX + 5][MAX + 5];
vector<iii> cases;

int min(int a, int b) {
	return a < b ? a : b;
}

int getmin() {
	int res = INF;
	for (int i = 1; i <= N; i++) {
		int subres = 0;
		for (int j = 1; j <= M; j++) 
			subres += A[i][j];
			
		res = min(res, subres);
	}
	
	return res;
}

int pop(queue<int>& q) {
	int res = q.front(); q.pop();
	return res;
}

void update(int r, int c, int s) {
	queue<int> q;
	
	int ltx = c - s;
	int lty = r - s;
	
	int rtx = c + s;
	int rby = r + s;
	
	for (int i = ltx; i <= rtx; i++) q.push(A[lty][i]);
	for (int i = lty + 1; i <= rby; i++) q.push(A[i][rtx]);
	for (int i = rtx - 1; i >= ltx; i--) q.push(A[rby][i]);
	for (int i = rby - 1; i > lty; i--) q.push(A[i][ltx]);
	
	for (int i = ltx + 1; i <= rtx; i++) A[lty][i] = pop(q);
	for (int i = lty + 1; i <= rby; i++) A[i][rtx] = pop(q);
	for (int i = rtx - 1; i >= ltx; i--) A[rby][i] = pop(q);
	for (int i = rby - 1; i >= lty; i--) A[i][ltx] = pop(q);
	
	if (s > 1) {
		update(r, c, s - 1);
	}
}

void init() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			A[i][j] = B[i][j];
}

int main(void) {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &B[i][j]);
			
	for (int i = 0; i < K; i++) {
		int r, c, s; 
		
		scanf("%d %d %d", &r, &c, &s);
		
		cases.push_back({r, {c, s}});
	}
	
	sort(cases.begin(), cases.end());
	
	int res = INF;
	do {
		init();
		
		for (int i = 0; i < K; i++) {
			int r = cases[i].first;
			int c = cases[i].second.first;
			int s = cases[i].second.second;
			
			update(r, c, s);
		}
		
		res = min(res, getmin());
	} while (next_permutation(cases.begin(), cases.end()));
	
	printf("%d\n", res);
	
	return 0;
}