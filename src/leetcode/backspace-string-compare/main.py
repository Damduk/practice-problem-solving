class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        s = list()
        t = list()
        
        sz = max(len(S), len(T))
        for idx in range(sz):
            if len(S) > idx:
                if S[idx] == '#':
                    if len(s) > 0:
                        s.pop()
                else:
                    s.append(S[idx])
            
            if len(T) > idx:
                if T[idx] == '#':
                    if len(t) > 0:
                        t.pop()
                else:
                    t.append(T[idx])
            
        return s == t