#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1001];
int N;

int solve(const vector<int>& arr) {
    for (int i = 1; i <= N; i++) {
        int mini = 0;
        
        for (int j = 1; j < i; j++) 
            if (arr[j] < arr[i] && mini < dp[j])
                mini = dp[j];
        
        dp[i] = mini + 1;
    }
    
    return *max_element(dp + 1, dp + N + 1);
}

int main() {
    scanf("%d", &N);
    
    vector<int> arr(N + 1);
    
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    
    printf("%d\n", solve(arr));
}