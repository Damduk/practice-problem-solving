#include <cstdio>
#include <vector>

using namespace std;

vector<int> v;
int select[10];

void backtracking(int n, int m, int ele) {
	if (ele > n || v.size() > m) return;

	v.push_back(ele);
	select[ele] = 1;
	
	if (v.size() == m) {
		for (int x : v) 
			printf("%d ", x);
			
		printf("\n");
	} else {
		for (int next = 1; next <= n; next++) {
			if (select[next]) {
				continue;
			}
			
			backtracking(n, m, next);
		}
	}
	
	v.pop_back();
	select[ele] = 0;
}

int main(void) {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		backtracking(N, M, i);
	}
	
	return 0;
}