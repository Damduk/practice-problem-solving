#include <iostream>

using namespace std;

typedef long long ll;

int A, B;        

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcd(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        scanf("%d %d", &A, &B);
        printf("%lld\n", lcd(A, B));
    }
}