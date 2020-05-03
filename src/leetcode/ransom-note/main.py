class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        available = dict()
        for c in magazine:
            available[c] = available.get(c, 0) + 1
        
        for c in ransomNote:
            sz = available.get(c, 0)
            if not sz:
                return False
            
            available[c] = sz - 1
            
        return True