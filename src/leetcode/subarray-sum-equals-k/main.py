class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sz = len(nums)
        if sz <= 0:
            return 0
        
        psum = [0 for _ in range(sz)]
        psum[0] = nums[0]
        
        for i in range(1, sz):
            psum[i] = psum[i - 1] + nums[i] 
            
        cache = dict()
        cache[0] = 1
        
        res = 0
        for i in range(sz):
            p = psum[i] - k
            v = cache.get(p, -1)
            if v != -1:
                res += v
                
            cache[psum[i]] = cache.get(psum[i], 0) + 1
        
        return res