#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll INF = 1;

class SegmentTree{
private:
	int _n;
	vi _tree;
	
	int left(int node) {
		return node << 1;
	}
	
	int right(int node) {
		return (node << 1) + 1;
	}
	
	ll priority(const ll& a, const ll& b) {
		return ((a % MOD) * (b % MOD)) % MOD;
	}
	
	ll build(const vi& src, int node, int l, int r) {
		if (l == r) {
			return _tree[node] = src[l];
		}
		
		int mid = (l + r) / 2;
		ll lVal = build(src, left(node), l, mid);
		ll rVal = build(src, right(node), mid+1, r);
		
		return _tree[node] = priority(lVal, rVal);
	}
	
	ll innerQuery(int queryL, int queryR, int node, int nodeL, int nodeR) {
		// Outside
		if (queryR < nodeL || nodeR < queryL) {
			return INF;
		}
		
		if (queryL <= nodeL && nodeR <= queryR) {
			return _tree[node];
		}
		
		int mid = (nodeL + nodeR) / 2;
		ll lVal = innerQuery(queryL, queryR, left(node), nodeL, mid);
		ll rVal = innerQuery(queryL, queryR, right(node), mid+1, nodeR);
		
		return priority(lVal, rVal);
	}
	
	ll innerUpdate(int idx, int newVal, int node, int l, int r) {
		if (idx < l || r < idx) {
			return _tree[node];
		}
		
		if (l == r) {
			return _tree[node] = newVal;
		} 
		
		int mid = (l + r) / 2;
		ll lVal = innerUpdate(idx, newVal, left(node), l, mid);
		ll rVal = innerUpdate(idx, newVal, right(node), mid+1, r);
		
		return _tree[node] = priority(lVal, rVal);
	}
public:
	SegmentTree(const vi& src) {
		_n = src.size();
		_tree = vi(_n * 4, 0);

		build(src, 1, 0, _n - 1);
	}
	
	ll query(int l, int r) {
		return innerQuery(l - 1, r - 1, 1, 0, _n - 1);
	}
	
	void update(int idx, int newVal) {
		innerUpdate(idx - 1, newVal, 1, 0, _n - 1);
	}
};

int N, M, K;

int main(void) {
	scanf("%d %d %d", &N, &M, &K);
	
	vi v = vi(N, 0);
	for (int i = 0; i < N; i++) 
		scanf("%lld", &v[i]);
		
	SegmentTree* st = new SegmentTree(v);
		
	int queryLen = M + K;
	for (int i = 0; i < queryLen; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		if (a == 2) {
			ll result = st->query(b, c);
			printf("%lld\n", result);
		} else if (a == 1) {
			st->update(b, c);
		}
	}
	
	return 0;
}