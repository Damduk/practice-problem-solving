#include <iostream>
#include <cstring>
#define MOD 10007

using namespace std;

int fibo[1010];
int N;

int f(int n) {
    if (n <= 1) 
        return n;

    int& ret = fibo[n];
    if (ret != -1)
        return ret;

    return ret = (f(n - 2) + f(n - 1)) % MOD;
}

int main(void) {
    memset(fibo, -1, sizeof(fibo)); 

    scanf("%d", &N);

    printf("%d\n", f(N + 1)); 

    return 0;
}
