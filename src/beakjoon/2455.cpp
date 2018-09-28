#define LOCAL_TEST

#include <iostream>

using namespace std;

int res;
int sum = 0;

void update(int x) {
    if (res < x) {
        res = x;
    }
}
int main(void) {
#ifdef LOCAL_TEST
    freopen("2455.txt", "r", stdin);
#endif
    for (int i = 0; i < 4; i++) {
        int in, out;

        scanf("%d %d", &out, &in);

        sum -= out;

        update(sum);

        sum += in;

        update(sum);
    }

    printf("%d\n", res);

    return 0;
}
