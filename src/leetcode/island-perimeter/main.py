dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        M = len(grid)
        N = len(grid[0])
        
        visited = [[0 for _ in range(N)] for _ in range(M)]
        
        def out(y, x):
            return y < 0 or x < 0 or y >= M or x >= N
        
        def dfs(y, x):
            visited[y][x] = 1
            
            res = 0
            for d in range(4):
                nx = x + dx[d]
                ny = y + dy[d]
                
                if out(ny, nx) or grid[ny][nx] == 0:
                    res += 1
                elif not visited[ny][nx]:
                    res += dfs(ny, nx)
            
            return res
        
        res = 0
        for i in range(M):
            for j in range(N):
                if grid[i][j] == 1:
                    return dfs(i, j)
        
        return res
            