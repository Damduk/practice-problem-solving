class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        h = dict({
            0: -1
        })
        
        res = cnt = 0
        for idx, digit in enumerate(nums):
            cnt += -1 if not digit else 1
            if cnt in h:
                res = max(res, idx - h[cnt])
            else:
                h[cnt] = idx
                          
        return res
            
            
        