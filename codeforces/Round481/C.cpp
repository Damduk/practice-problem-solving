#include <iostream>

using namespace std;

typedef long long ll;

int N, M;
ll sum_room[2 * 10 * 10 * 10 * 10 * 10 + 5];

int main() {
    scanf("%d %d", &N, &M);
    
    sum_room[0] = 0;
    
    for (int i = 0; i < N; i++) {
        ll x;
        
        scanf("%lld", &x);
        
        sum_room[i + 1] = x + sum_room[i];
    }
    
    ll dom = 1, num;

    for (int i = 0; i < M; i++) {
        ll let;
        
        scanf("%lld", &let);
        
        for (ll j = dom; j <= M; j++) {           
            if (let <= sum_room[j]) {
                dom = j;
                num = let - sum_room[dom - 1];
                break;
            }          
        }
        
        printf("%lld %lld\n", dom, num);
    }
}