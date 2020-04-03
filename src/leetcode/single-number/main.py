class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        print(nums)
        idx = 0
        size = len(nums)
        while idx < size:
            if idx + 1 < size:
                if nums[idx] != nums[idx + 1]:
                    break
                else:
                    while nums[idx] == nums[idx + 1]:
                        idx += 1
            else:
                break
                
            idx += 1;
        
        return nums[idx]
        