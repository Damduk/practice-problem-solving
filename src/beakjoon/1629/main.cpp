#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

LL A, B, C;

LL calculate(LL A, LL B, LL C) {
    A %= C;

    if (B == 0) 
        return 1;
    else if (B % 2 == 0) 
        return calculate(A * A, B >> 1, C) % C;
    else
        return (A * calculate(A * A, (B - 1) >> 1, C)) % C;
}

int main(void) {
    freopen("input.txt", "r", stdin);

    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld\n", calculate(A, B, C));

    return 0;
}
