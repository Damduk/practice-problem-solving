#include <iostream>
#include <cstring>
#define MOD 10007
#define MAX 1000

using namespace std;

int cache[MAX + 10];
int N;

int main(void) {
    scanf("%d", &N);
    
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 3;
    
    for (int i = 3; i <= MAX; i++) {
        cache[i] = (((2 * cache[i - 2]) % MOD) + (cache[i - 1] % MOD)) % MOD;
    }

    printf("%d\n", cache[N]);

    return 0;
}
