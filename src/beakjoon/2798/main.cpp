#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[101];

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int ret = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;	

			for (int k = 0; k < N; k++) {
				if (i == k || j == k) continue;

				const int s = A[i] + A[j] + A[k];
				if (s > M) {
					continue;
				}	

				ret = max(ret, s);
			}
		} 
	}	

	printf("%d\n", ret);

	return 0;
}
