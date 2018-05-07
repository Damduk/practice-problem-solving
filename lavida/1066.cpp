#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int board[101][101];
int N;

int get_true() {
    int result = 0;
    
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            result += board[i][j];
        
    return result;
}

int get_area(const vector<pair<int, int>> pos) {
    for (auto& item : pos) {
        int width = item.first + 10;
        int height = item.second + 10;
        
        for (int i = item.first; i < width; i++)
            for (int j = item.second; j < height; j++)
                board[i][j] = 1;
    }
    
    return get_true();
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        memset(board, 0, sizeof(board));  
        
        scanf("%d", &N);
        
        vector<pair<int, int>> pos;
        
        while (N--) {
            int x, y;
            
            scanf("%d %d", &x, &y);
            
            pos.push_back({x, y});
        }
        
        printf("%d\n", get_area(pos));
    }
}