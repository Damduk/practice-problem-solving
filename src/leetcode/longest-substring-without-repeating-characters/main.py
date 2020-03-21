def solve(str, idx):
    strlen = len(str)
    substr = str[idx]
    
    for next in range(idx + 1, strlen):
        if str[next] in substr:
            break
        else:
            substr += str[next]
    
    return len(substr)
    
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        for i in range(0, len(s)):
            res = max(res, solve(s, i))
        return res

        