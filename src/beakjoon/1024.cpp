#include <iostream>

int N, L;

void printResult(int pivot, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", pivot++);
}

int getSum(int pivot, int len) {
    int result = 0;

    while (len--)
        result += pivot++;

    return result;
}

int findPivot(int len) {
    int quotient = N / len;
    int remain = N % len;
    int pivot1 = quotient - (len / 2);
    int pivot2 = (quotient + 1) - (len / 2);

    if ((len & 1) && remain == 0)
        return pivot1 > -1 ? pivot1 : -1;

    int sum1 = pivot1 > -1 ? getSum(pivot1, len) : -1;
    int sum2 = pivot2 > -1 ? getSum(pivot2, len) : -1;

    if (sum1 == N)
        return pivot1;
    else if (sum2 == N)
        return pivot2;

    return -1;
}

int solve() {
    for (int i = L; i < 101; i++) {
        if (i == 2 && !(N & 1)) continue;

        int pivot = findPivot(i);
        if (pivot != -1) {
            printResult(pivot, i);
            return 0;
        }
    }

    return -1;
}

int main(void) {
    scanf("%d %d", &N, &L);

    int result = solve();
    if (result == -1) {
        printf("-1\n");
    }

    return 0;
}