#define LOCAL
#include <bits/stdc++.h>
#define MAX 1002

using namespace std;

char str1[MAX];
char str2[MAX];
int DP[MAX][MAX];

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%s %s", str1, str2);

	for (int i = 1; i <= strlen(str1); i++) {
		for (int j = 1; j <= strlen(str2); j++) {
			DP[i][j] = str1[i - 1] == str2[j - 1] ? DP[i-1][j-1] + 1 : max(DP[i][j-1], DP[i-1][j]);
		}
	}

	int sol = DP[strlen(str1)][strlen(str2)];

	printf("%d\n", sol);

	return 0;
}

