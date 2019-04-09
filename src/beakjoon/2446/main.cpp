#include <bits/stdc++.h>

using namespace std;

int N;

int printLine(int n) {
    int space = n - 1;
    for (int i = 0; i < space; i++)
        printf(" ");

    int star = (N - n + 1) * 2 - 1;
    for (int i = 0; i < star; i++)
        printf("*");

    printf("\n");
}

int main(void) {
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++)
        printLine(i);

    for (int i = N - 1; i > 0; i--)
        printLine(i);

    return 0;
}
