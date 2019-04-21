#include <bits/stdc++.h>

using namespace std;

int col[20];
int N;

int pomise(int q) {
    for (int i = 0; i < q; i++) {
        if (col[q] == col[i] || abs(col[q] - col[i]) == q - i) {
            return false;
        }
    }

    return true;
}

int f(int q) {
    if (q == N) return 1;
   
    int result = 0;
    for (int i = 0; i < N; i++) {
        col[q] = i;

        if (pomise(q)) {
            result += f(q + 1);
        }
    }

    return result;
}   

int main(void) {
    scanf("%d", &N);

    int result = f(0);

    printf("%d\n", result);

    return 0;
}
