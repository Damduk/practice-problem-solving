#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

vector<ii> arr;

int N, vote[7];

bool cmp(const ii& p1, const ii& p2) {
    return p1.first < p2.first;
}

void init() {
    for (int i = 1; i <= 7; i++)
        arr.push_back({0, i});

    for (int i = 1; i <= 7; i++)
        vote[i - 1] = pow(2, i);
}

void reserve() {
    for (int i = 0; i < 7; i++) { 
        arr[i].first = 0;
        arr[i].second = i + 1;
    }

    for (auto& item : arr)
        item.first = 0;
}

int main() {
    freopen("1761.in", "r", stdin);

    int TC;

    scanf("%d", &TC);

    init();

    while (TC--) {
        scanf("%d", &N);

        reserve();

        for (int i = 0; i < N; i++) {
            int code;

            scanf("%d", &code);

            for (int j = 6; j >= 0; j--) {
                if (vote[j] > code)
                    continue;

                code -= vote[j];
                arr[j].first++;
            }
        }

        sort(arr.begin(), arr.end(), cmp);
 
        if (arr[0].first == arr[1].first || arr[6].first == arr[5].first)
            printf("Nagari\n");
        else
            printf("%d/%d\n", arr[6].second, arr[0].second);
    }
}
