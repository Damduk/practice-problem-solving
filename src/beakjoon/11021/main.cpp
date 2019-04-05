#include <iostream>

using namespace std;

int TC;
int A, B;

int main(void) {
    scanf("%d", &TC);

    for (int i = 1; i <= TC; i++) {
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i, A + B);
    }

    return 0;
}
