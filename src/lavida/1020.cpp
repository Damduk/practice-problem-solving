#include <iostream>

using namespace std;

int N;

bool solve() {
    if (N < 4)
        return false;
    if (N & 1)
        return false;

    printf("%d %d\n", 2, N - 2);

    return true;
}

int main() {
    freopen("1020.in", "r", stdin);

    int TC;

    scanf("%d", &TC);

    while (TC--) {
        scanf("%d", &N);

        if (!solve())
            printf("NO\n");
    }
}
