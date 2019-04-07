#include <iostream>

using namespace std;

int N;

int main(void) {
    scanf("%d", &N);

    for (int i = N; i > 0; i--) {
        int space = N - i;

        for (int j = 0; j < space; j++) 
            printf(" ");

        int len = 2 * i - 1;

        for (int j = 0; j < len; j++) 
            printf("*");

        printf("\n");
    }

    return 0;
}
