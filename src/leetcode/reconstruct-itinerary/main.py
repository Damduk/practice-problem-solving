class Node:
    to: str
    fr: str
    sz: int
        
    def __init__(self, to, fr, sz):
        self.to = to
        self.fr = fr
        self.sz = sz

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj = dict()
        adjmap = dict()
        
        ticket_cnt = 0
        for ticket in tickets:
            ticket_cnt += 1
            to, fr = ticket
            
            DEFAULT_NODE = Node(to, fr, 0)
            
            adjmap[to][fr] = adjmap.setdefault(to, dict()).setdefault(fr, DEFAULT_NODE)
            adj_list = adj.setdefault(to, list())
            
            if adjmap[to][fr].sz == 0:
                adj_list.append(adjmap[to][fr])
                
            adjmap[to][fr].sz += 1
        
        for k, v in adj.items():
            v.sort(key=lambda x: x.fr)
        
        end = False
        ctx = list()
        def dfs(node):
            nonlocal end
            nonlocal ctx
            
            ctx.append(node)
            
            if ticket_cnt + 1 == len(ctx):
                end = True
                return
            
            for n in adj.get(node, []):
                if not end and n.sz > 0:
                    n.sz -= 1
                    dfs(n.fr)
                    n.sz += 1
            
            if not end:
                ctx.pop()
        
        dfs('JFK')
        
        return ctx
            