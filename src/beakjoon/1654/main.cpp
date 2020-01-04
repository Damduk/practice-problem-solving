#include <cstdio>
#include <climits>

typedef long long ll;

ll N, K;
ll A[1000005];

ll max(ll a, ll b) {
	return a > b ? a : b;
}

ll f(ll mid) {
	ll n = 0;

	for (int i = 0; i < K; i++) {
		n = n + (A[i] / mid);
	}
	
	return n;
}

int main(void) {
	scanf("%lld %lld", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%lld", &A[i]);
	}
	
	ll res = -1;
	ll left = 0, right = LLONG_MAX;
	
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll fmid = f(mid);
		
		if (N <= fmid) {
			res = max(res, mid);
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	
	printf("%lld\n", res);
}