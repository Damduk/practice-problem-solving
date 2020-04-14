class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        pidx = 0
        slen = len(s)
        
        for d, amount in shift:
            if not d:
                pidx += amount
                pidx %= slen
            else:
                pidx -= amount
                if pidx < 0:
                    pidx += slen
        
        return s[pidx:slen] + s[0:pidx]