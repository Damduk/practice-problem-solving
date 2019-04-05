#include <iostream>

using namespace std;

int N;

void print(int height) {
    int space = N - height;
    for (int i = 0; i < space; i++)
        printf(" ");

    int star = 2 * height - 1;
    for (int i = 0; i < star; i++)
        printf("*");

    printf("\n");
}

int main(void) {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        print(i);
    }

    for (int i = N - 1; i > 0; i--) {
        print(i);
    }

    return 0;
}
