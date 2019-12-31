#include <cstdio>

int main(void) {
    int idx;
    int max = -1;

    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int tmp; scanf("%d", &tmp);
            sum += tmp;
        }

        if (max < sum) {
            max = sum;
            idx = i + 1;
        }
    }

    printf("%d %d\n", idx, max);
    return 0;
}
