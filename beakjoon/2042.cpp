#include <iostream>

using namespace std;

typedef long long ll;

ll tree[4000001];

void update(int cur, int left, int right, int tar, ll val) {
    if (tar < left || right < tar) return;    
    if (left == right) {
        tree[cur] = val;
        return;
    }
    
    int mid = (left + right) / 2;
    
    update(cur * 2, left, mid, tar, val);
    update(cur * 2 + 1, mid + 1, right, tar, val);
    
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}

ll query(int cur, int start, int end, int left, int right) {
    if (start > right || left > end) return 0LL;
    if (left <= start && end <= right) return tree[cur];
    
    int mid = (start + end) / 2;
    ll left_child = query(cur * 2, start, mid, left, right);
    ll right_child = query(cur * 2 + 1, mid + 1, end, left, right);
    
    return left_child + right_child;
}

int main() {
    int N, M, K;
    
    scanf("%d %d %d", &N, &M, &K);
    
    for (int i = 1; i <= N; i++) {
        ll x;
        
        scanf("%d", &x);
        
        update(1, 1, N, i, x);
    }
    
    M += K;
    
    while (M--) {
        ll a, b, c;
        
        scanf("%lld %lld %lld", &a, &b, &c);
        
        if (a == 1) {
            update(1, 1, N, b, c);
        } else {
            printf("%lld\n", query(1, 1, N, b, c));
        }
    }
}