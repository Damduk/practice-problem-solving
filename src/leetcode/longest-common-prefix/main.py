class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        s = ''
        
        lengths = [len(x) for x in strs]
        sz = max(lengths) if lengths else 0

        for idx in range(sz):        
            if len(strs[0]) <= idx:
                break
                
            c = strs[0][idx]
            out = False      
            for item in strs:
                if len(item) <= idx or c != item[idx]:
                    out = True
                    break
                    
            if out:
                break
            
            s += c
    
        return s
            