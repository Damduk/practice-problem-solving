#include <bits/stdc++.h>

using namespace std;

int N;

void printLine(int n) {
    int space = N - n;
    for (int i = 0; i < space; i++)
        printf(" ");

    int star = n;
    for (int i = 0; i < star; i++)
        printf("*");

    printf("\n");
}


int main(void) {
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        printLine(i);
    }

    for (int i = N - 1; i >= 0; i--) {
        printLine(i);
    }
    return 0;
}
