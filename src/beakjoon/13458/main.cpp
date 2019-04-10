#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL arr[1000001];
LL N;
LL major, sub;

int main(void) {
    scanf("%lld", &N);
    
    for (int i = 0; i < N; i++)
        scanf("%lld", &arr[i]);

    scanf("%lld %lld", &major, &sub);

    LL result = 0;
    for (int i = 0; i < N; i++) {
        arr[i] -= major;
        result++;

        if (arr[i] > 0)
            result += (arr[i] % sub == 0) ? (arr[i] / sub) : ((arr[i] / sub) + 1);
    }

    printf("%lld\n", result);

    return 0;
}
