#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int N, A[1005];
int DP[1005];

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &A[i]);
	
	for (int i = 0; i < N; i++) {
		DP[i] = 1;

		for (int j = 0; j < N; j++) {
			if (A[i] < A[j] && DP[j] + 1 > DP[i]) {
				DP[i] = DP[j] + 1;
			}
		}
	}
	
	int res = -1;
	for (int i = 0; i < N; i++) 
		res = max(res, DP[i]);
	
	printf("%d\n", res);

	return 0;
}
