#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 101;

int A[MAX][MAX];
int DP[MAX][MAX];
int n;

int solve(int x, int y) {
    if (x > n || y > n)
        return -MAX;
    if (x == n && y == n)
        return A[y][x];
    
    int& ret = DP[y][x];
    if (ret != -1)
        return ret;
    
    return ret = A[y][x] + max(solve(x, y + 1), solve(x + 1, y));
}

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            scanf("%d", &A[i][j]);
              
    memset(DP, -1, sizeof(DP));    
        
    printf("%d\n", solve(1, 1));
}