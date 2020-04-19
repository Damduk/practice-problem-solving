#include <cstdio>
#include <cstdlib>
#include <vector>
#define MAX 9

using namespace std;

typedef pair<int, int> ii;

int grid[MAX][MAX];
vector<ii> zero;

void printGrid() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", grid[i][j]);
        }
        
        printf("\n");
    }
}

vector<int> getAvailableNums(int x, int y) {
    int visited[10] = { 0 };
    for (int i = 0; i < MAX; i++)
        if (grid[y][i] != 0)
            visited[grid[y][i]] = true;
    for (int i = 0; i < MAX; i++)
        if (grid[i][x] != 0)
            visited[grid[i][x]] = true;
    
    x = (x / 3) * 3;
    y = (y / 3) * 3;
    
    for (int i = y; i < y + 3; i++)
        for (int j = x; j < x + 3; j++)
            if (grid[i][j] != 0)
                visited[grid[i][j]] = true;
            
    vector<int> res;   
    for (int i = 1; i <= MAX; i++)
        if (!visited[i])
            res.push_back(i);
            
    return res;
}

void solve(int idx, int remain) {
    if (remain < 1) {
        printGrid();
        exit(0);
    }
    
    if (idx >= zero.size()) {
        return;
    }
    
    ii pos = zero[idx];
    
    int& target = grid[pos.second][pos.first];
    vector<int> nums = getAvailableNums(pos.first, pos.second);
    
    for (int n : nums) {
        target = n;
        solve(idx + 1, remain - 1);
        target = 0;
    }
}

int main(void) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            scanf("%d", &grid[i][j]);
            if (grid[i][j] == 0) {
                zero.push_back({j, i});
            }
        }
    }
    
    solve(0, zero.size());
    return 0;
}