INF = 100000000000
DX = [ 0, 1 ]
DY = [ 1, 0 ]

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        
        # y x
        M, N = len(grid), len(grid[0]) 
        cache = dict()
        
        def is_valid(x, y):
            return 0 <= x < N and 0 <= y < M
        
        def solve(x, y):
            if x == N - 1 and y == M - 1:
                return grid[y][x]
            
            if (x,y) in cache:
                return cache[(x,y)]
            
            ret = INF
            for dx, dy in zip(DX, DY):
                nx = x + dx
                ny = y + dy
                if is_valid(nx, ny):
                    ret = min(ret, grid[y][x] + solve(nx, ny))
            
            cache[(x,y)] = ret
            return ret
        
        return solve(0, 0)