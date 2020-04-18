DX = [ 1, 0, -1, 0 ]
DY = [ 0, 1, 0, -1 ]

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        N, M = len(grid), len(grid[0])
        visited = [[ False for _ in range(M)] for _ in range(N)]

        def is_valid(x, y):
            return 0 <= x < M and 0 <= y < N
        
        def dfs(x, y):
            visited[y][x] = True
            for dx, dy in zip(DX, DY):
                nx = x + dx
                ny = y + dy
                if not is_valid(nx, ny):
                    continue
                
                if grid[ny][nx] == '1' and not visited[ny][nx]:
                    dfs(nx, ny)

        res = 0
        for i in range(N):
            for j in range(M):
                if grid[i][j] == '0' or visited[i][j]:
                    continue
                
                dfs(j, i)
                res += 1
            
        return res
