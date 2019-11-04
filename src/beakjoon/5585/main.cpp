#include <bits/stdc++.h>

using namespace std;

int remain[] = { 500, 100, 50, 10, 5, 1 };

int main(void) {
	int N; scanf("%d", &N);

	N = 1000 - N;
	
	int ret = 0;
	int idx = 0;
	while (N) {
		if (N >= remain[idx]) {
			N -= remain[idx];
			ret++;
		} else {
			idx++;
		}	
	}

	printf("%d\n", ret);

	return 0;
}
