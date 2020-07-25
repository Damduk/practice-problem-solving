class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        N = len(graph)
        
        res = []
        path = []
        visited = [False for _ in range(N)]
        
        def dfs(node):
            if node == N - 1:
                tmp = list(path)
                tmp.append(node)
                
                res.append(tmp)
                return
            
            path.append(node)
            visited[node] = True
            
            for next in graph[node]:
                if not visited[next]:
                    dfs(next)
                    
            visited[node] = False
            path.pop()
            
        dfs(0)
        
        return res