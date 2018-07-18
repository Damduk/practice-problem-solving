#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> arr;
int N;

int solve() {
    dp.push_back(arr[1]);
    
    for (int i = 2; i <= N; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        
        if (it == dp.end())
            dp.push_back(arr[i]);
        else
            *it = arr[i];
    }

    return dp.size();
}

int main() {
    scanf("%d", &N);

    arr.reserve(N + 1);
    
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", solve());
}