#define LOCAL
#include <bits/stdc++.h>

using namespace std;

int year;

int getAnswer(int year) {
    return (year % 4 == 0) && 
        ((year % 100 != 0) || (year % 400 == 0));
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &year);

    int ans = getAnswer(year);

    printf("%d\n", ans);

    return 0;
}
