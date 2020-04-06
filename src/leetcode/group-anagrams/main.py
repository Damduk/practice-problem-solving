class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = dict()
        for s in strs:
            sorteds = str(sorted(s))
            if not sorteds in d:
                d[sorteds] = list()
                
            d[sorteds].append(s)
            
        return list(v for v in d.values())
        