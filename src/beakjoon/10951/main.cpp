#define LOCAL
#include <iostream>

using namespace std;

int A, B;

int main(void) {
#ifdef LOCAL 
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d", &A, &B) != EOF) {
        printf("%d\n", A + B);
    }
}
