#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
int _cnt;

void hanoi(int src, int dest, int tmp, int n) {
	if (n < 1) {
		return;
	}
	
	hanoi(src, tmp, dest, n - 1);
	
	v.push_back({src, dest});
	
	hanoi(tmp, dest, src, n - 1);
	
	_cnt++;
}

int main(void) {
	int n;
	
	scanf("%d", &n);
	hanoi(1, 3, 2, n);
	
	printf("%d\n", _cnt);
	for (auto& p : v) {
		printf("%d %d\n", p.first, p.second);
	}
	
	return 0;
}
