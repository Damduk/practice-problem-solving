#include <iostream>
#define MAX 300

using namespace std;

int N, M;

int solve() {
    return N * M - 1;
}

int main(void) {
    scanf("%d %d", &N, &M);
    printf("%d\n", solve());

    return 0;
}
