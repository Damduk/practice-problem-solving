#include <iostream>
#include <algorithm>
#define MAX 1000

using namespace std;

int N;
int arr[MAX + 10];
int sum[MAX + 10];
int ans;

int main(void) {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + N + 1);

    for (int i = 1; i <= N; i++) {
        sum[i] = arr[i] + sum[i - 1];
        ans += sum[i];
    }

    printf("%d\n", ans);
    return 0;
}
