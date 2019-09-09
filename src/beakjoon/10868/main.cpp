#define LOCAL
#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9;

class SegmentTree{
private:
	vector<int> _st;
	int _size;

	int left(int node) { return node << 1; }
	int right(int node) { return (node << 1) + 1; }
	
	void build(const vector<int>& v, int node, int L, int R) {
		if (L == R) {
			_st[node] = v[L];
			return;
		}

		int mid = (L + R) / 2;
		
		build(v, left(node), L, mid);
		build(v, right(node), mid + 1, R);

		_st[node] = min(_st[left(node)], _st[right(node)]);	
	}	

	int innerQuery(int node, int curL, int curR, int queryL, int queryR) {
		if (curL > queryR || curR < queryL ) return INF;	
		if (curL >= queryL && curR <= queryR) return _st[node];

		int mid = (curL + curR) / 2;
		int v1 = innerQuery(left(node), curL, mid, queryL, queryR);
		int v2 = innerQuery(right(node), mid+1, curR, queryL, queryR); 

		return min(v1, v2);
	}

public:
	SegmentTree(const vector<int>& v) {
		_st = vector<int>(v.size() * 4, 0);
		_size = v.size();
	
		build(v, 1, 0, v.size() - 1);
	}

	int query(int l, int r) {
		return innerQuery(1, 0, _size - 1, l - 1, r - 1);
	}
};

int N, M;

int main(void) {
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &N, &M);

	const vector<int> v = vector<int>(N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &v[i]);

	const auto st = new SegmentTree(v);
	for (int i = 0; i < M; i++) {
		int l, r;

		scanf("%d %d", &l, &r);
		printf("%d\n", st->query(l, r));
	}

	delete st;
	
	return 0;
}
