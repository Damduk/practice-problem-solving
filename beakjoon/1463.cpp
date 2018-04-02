#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1000001;

int memo[MAX];
int n;

int solve() {
    memset(memo, MAX, sizeof(memo));
    
    memo[1] = 0;
    memo[2] = 1;
    memo[3] = 1;
    
    for (int i = 4; i <= n; i++) {
        int& result = memo[i];
        
        if (i % 3 == 0)
            result = min(result, memo[i / 3]);
        if (i % 2 == 0)
            result = min(result, memo[i / 2]);
        
        result = min(result, memo[i - 1]);
  
        result++;
    }
    
    return memo[n];
}

int main() {
    scanf("%d", &n);
    printf("%d\n", solve());
}