class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt = dict()
        major = len(nums) // 2
        
        for n in nums:
            cnt[n] = cnt.get(n, 0) + 1
            if cnt[n] > major:
                res = n
                break
    
        return res