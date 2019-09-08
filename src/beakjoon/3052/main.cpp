#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	set<int> s;

	int num;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &num);

		int rem = num % 42;

		s.insert(rem);	
	}

	printf("%d\n", s.size());

	return 0;
}
