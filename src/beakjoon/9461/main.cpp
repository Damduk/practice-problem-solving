#include <iostream>

using namespace std;

typedef long long ll;

ll S[105];

void init() {
    S[1] = S[2] = S[3] = 1;

    for (int i = 4; i <= 100; i++) 
        S[i] = S[i - 2] + S[i - 3];
}

int TC;
int N;

int main(void) {
    init();

    scanf("%d", &TC);

    while (TC--) {
        scanf("%d", &N);
        printf("%lld\n", S[N]);
    }

    return 0;
}
