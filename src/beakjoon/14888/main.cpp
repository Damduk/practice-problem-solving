#define LOCAL
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
int A[101];

char ops[4] = { '+', '-', '*', '/' };

ll execute(ll l, ll r, char op) {
	switch(op) {
		case '+':
			return l + r;
		case '-':
			return l - r;
		case '*':
			return l * r;
		case '/':
			return l / r;
	}
	return 0; 
}

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &A[i]);

	vector<char> op;

	for (int i = 0; i < 4; i++) {
		int cnt; scanf("%d", &cnt);

		for (int j = 0; j < cnt; j++) 
			op.push_back(ops[i]);	
	}

    sort(op.begin(), op.end());

	ll minValue = LLONG_MAX;
	ll maxValue = LLONG_MIN;
	do {
		ll v = A[0];		
		for (int i = 1; i < N; i++) 
			v = execute(v, A[i], op[i - 1]);

		minValue = min(minValue, v);
		maxValue = max(maxValue, v);
	} while(next_permutation(op.begin(), op.end()));

	printf("%lld\n", maxValue);
	printf("%lld\n", minValue);

	return 0;
}
