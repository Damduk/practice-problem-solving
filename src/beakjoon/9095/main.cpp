#include <iostream>
#include <cstdio>

using namespace std;

int cache[12];
int num[3] = {1, 2, 3};
int TC, N;

void init() {
    cache[0] = 1;
    cache[1] = 1;

    for (int i = 2; i <= 11; i++) {
        int way = 0;

        for (int j = 0; j < 3; j++) {
            int remain = i - num[j];
            if (remain < 0) {
                continue;
            }

            way += cache[remain];
        }

        cache[i] = way;
    }
}

int main(void) {
    init();

    scanf("%d", &TC);

    while (TC--) {
        scanf("%d", &N);
        printf("%d\n", cache[N]);
    }

    return 0;
}
