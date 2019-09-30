#include <bits/stdc++.h>

using namespace std;

int minFromN(const int N) {
	int a = 0, b = 0;

	for (int j = 1; j <= N; j++) {
		int i = j;

		while (i % 2 == 0) {
			a++;
			i /= 2;
		}

		while (i % 5 == 0) {
			b++;
			i /= 5;
		}
	}

	return min(a, b);
}

int main(void) {
	int N; scanf("%d", &N);

	int minVal = minFromN(N);
	printf("%d", minVal);
	return 0;
}
