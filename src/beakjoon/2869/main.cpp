#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int A, B, V; scanf("%d %d %d", &A, &B, &V);

	int sol = 1;
	V -= A;
	
	int b = A - B;
	sol += (V % b == 0 ? V / b : (V / b) + 1);

	printf("%d", sol);
	
	return 0;
}
