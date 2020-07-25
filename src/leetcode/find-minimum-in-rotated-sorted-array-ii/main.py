class Solution:
    def findMin(self, nums: List[int]) -> int:
        lo, hi = 0, len(nums) - 1
        
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if nums[mid] > nums[hi]:
                lo += 1
            elif nums[mid] < nums[lo]:
                hi = mid
            else:
                hi -= 1
            
        return nums[lo]