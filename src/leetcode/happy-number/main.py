def divide(n: int) -> List[int]:
    ret = []

    while n:
        a = n % 10
        n //= 10
        ret.append(a)

    return ret

class Solution:
    def isHappy(self, n: int) -> bool:
        visited = set()
        while n != 1:
            if n in visited:
                return False
            
            visited.add(n)
            
            n = reduce(lambda x, y: x+y, map(lambda x: x * x, divide(n)))
        
        return True