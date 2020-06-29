int DP[105][105];
int M, N;
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

bool isOut(int m, int n) {
    return m < 1 || n < 1 || m > M || n > N;
}

int dfs(int m, int n) {
    if (m == M && n == N) {
        return 1;
    } 
    
    int& ret = DP[m][n];
    if (ret != -1) {
        return ret;
    }
    
    ret = 0;
    for (int i = 0; i < 2; i++) {
        int nm = m + dx[i];
        int nn = n + dy[i];
        if (isOut(nm, nn)) {
            continue;
        }
        
        ret += dfs(nm, nn);
    }
    
    return ret;
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        
        memset(DP, -1, sizeof(DP));
        
        int res = dfs(1, 1);
        return res;
    }
};