#include <bits/stdc++.h>

using namespace std;

int E, S, M;
int e, s, m;
int result;

int main(void) {
    scanf("%d %d %d", &E, &S, &M);

    e = s = m = result = 1;

    while (e != E || s != S || m != M) {
        e = ((e + 1) % 15);
        e = e == 0 ? 15 : e;

        s = ((s + 1) % 28);
        s = s == 0 ? 28 : s;

        m = ((m + 1) % 19);
        m = m == 0 ? 19 : m;

        result++;
    }

    printf("%d\n", result);

    return 0;
}
