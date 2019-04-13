#define LOCAL
#include <bits/stdc++.h>
#define MAX 6

using namespace std;

int K;
int arr[20];
deque<int> dq;

void backTrack(int node, int len) {
    if (node > K) {
        return;
    }

    dq.push_back(arr[node]);

    if (dq.size() == MAX) {
        for (int item : dq) 
            printf("%d ", item);

        printf("\n");
    } else {
        for (int i = node + 1; i <= K; i++) {
            backTrack(i, len);
        }
    }

    dq.pop_back();
}

int main(void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &K) && K != 0) {
        dq = deque<int>();

        for (int i = 1; i <= K; i++) {
            scanf("%d", &arr[i]);
        }

        int len = K - MAX + 1;
        for (int i = 1; i <= len; i++) {
            int start = i;
            backTrack(start, len);
        }

        printf("\n");
    }

    return 0;
}
