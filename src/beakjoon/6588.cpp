#define local

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#define MAX 1000005

using namespace std;

int N;

vector<int> primes;
bool prime[MAX];

void init() {
    memset(prime, 1, sizeof(prime));

    int sqrtn = sqrt(MAX);
    for (int i = 3; i <= MAX; i += 2) {
        if (prime[i])
            primes.push_back(i);
       
        for (int j = i + i; j <= MAX; j += i) {
            prime[j] = false;
        }
    }
}

int main(void) {
#ifdef local
    freopen("6488.in.txt", "r", stdin);
#endif
    init();

    while (1) {
        scanf("%d", &N);

        if (N < 5) {
            break;
        }

        int first = 0, second = 0;
        for (auto& i : primes) {
            int remain = N - i;
            if (prime[remain]) {
                first = i;
                second = remain;
                break;
            }
        }

        printf("%d = %d + %d\n", N, first, second);
    }

    return 0;
}
