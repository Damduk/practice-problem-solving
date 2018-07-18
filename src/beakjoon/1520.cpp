#include <iostream>
#include <cstring>

using namespace std;

const int BOARD_MAX = 502;

int DP[BOARD_MAX][BOARD_MAX];
int board[BOARD_MAX][BOARD_MAX];
int h, w;

int dp(const int& x, const int& y, const int& prev) {
    if (x < 0 || y < 0) return 0;
    if (x >= w || y >= h) return 0;
    if (board[y][x] >= prev) return 0;
    if (x == w - 1 && y == h - 1) return 1;
    
    int& ret = DP[y][x];
    if (ret != -1)
        return ret;

    int a = dp(x + 1, y, board[y][x]) + dp(x, y + 1, board[y][x]);
    int b = dp(x - 1, y, board[y][x]) + dp(x, y - 1, board[y][x]);
    
    return ret = a + b;
}

int solve() {
    memset(DP, -1, sizeof(DP));
    
    return dp(0, 0, 10001);
}

int main() {
    scanf("%d %d", &h, &w);
    
    for (int i = 0; i < h; i++) 
        for (int j = 0; j < w; j++)
            scanf("%d", &board[i][j]); 
        
    printf("%d\n", solve());
}