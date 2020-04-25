class Solution:
    def canJump(self, nums: List[int]) -> bool:
        sz = len(nums)
        if sz <= 0:
            return False
        
        idx = 0
        remain = nums[0]
        while remain:
            if idx == sz - 1:
                break
                
            remain -= 1
            idx += 1
            remain = max(remain, nums[idx])
                
        return idx == sz - 1