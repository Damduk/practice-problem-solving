class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        
        N = len(matrix)
        M = len(matrix[0])
        
        def is_out(x, y):
            return x < 0 or y < 0 or x >= M or y >= N
        
        def check(sz, x, y):
            for i in range(y, y + sz):
                for j in range(x, x + sz):
                    if matrix[i][j] == '0':
                        return 0
                    
            return sz * sz
        
        
        sz = 1
        ans = 0
        
        for i in range(N):
            for j in range(M):
                while not is_out(j + sz - 1, i + sz - 1):
                    res = check(sz, j, i)
                    if res <= 0:
                        break
                        
                    ans = max(ans, res)
                    sz += 1
        
        return ans