# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, x: int, y: int) -> int:
#    def dimensions(self) -> list[]:

INF = 100000000000

class Solution:
    def leftMostColumnWithOne(self, m: 'BinaryMatrix') -> int:
        def search(row, l, r): 
            if (l > r):
                return INF
            
            mid = (l + r) // 2
            midv = m.get(row, mid)
            if midv == 0:
                return search(row, mid + 1, r)
            elif mid == 0 or m.get(row, mid - 1) == 0:
                return mid
            else:
                return search(row, l, mid - 1)
            
        
        N, M = m.dimensions()
        res = INF
        for i in range(N):
            res = min(res, search(i, 0, M - 1))
        
        return res if res != INF else -1