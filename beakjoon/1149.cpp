#include <iostream>
#include <cstring>

#define COLOR_LEN 3
#define HOUSE_LEN 1001

using namespace std;

int house[HOUSE_LEN][COLOR_LEN];
int dp[HOUSE_LEN][COLOR_LEN];
int n;

int get_value(int cur, int color) {
    if (cur == n)
        return house[cur][color];
    
    int& ret = dp[cur][color];
    if (ret != -1)
        return ret;
    
    int next1 = get_value(cur + 1, (color + 1) % COLOR_LEN);
    int next2 = get_value(cur + 1, (color + 2) % COLOR_LEN);
    
    return ret = house[cur][color] + min(next1, next2);
}

int solve() {
    memset(dp, -1, sizeof(dp));
    
    int a = get_value(0, 0);
    int b = get_value(0, 1);
    int c = get_value(0, 2);
    
    return min(a, min(b, c));
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) 
        scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
    
    printf("%d\n", solve());
}