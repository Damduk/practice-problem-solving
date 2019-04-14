#include <iostream>

using namespace std;

int main(void) {
    int TC;

    scanf("%d", &TC);

    while (TC--) {
        int A, B; scanf("%d %d", &A, &B);

        printf("%d\n", A + B);
    }

    return 0;
}
