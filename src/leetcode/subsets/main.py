class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:  
        res = [[]]
        
        sz = len(nums)
        def choice(st, idx):
            nonlocal res
            
            st.append(nums[idx])
            res.append(list(st))
            
            for n in range(idx + 1, sz):
                choice(st, n)
                
            st.pop()
               
        st = []        
        for idx in range(sz):
            choice(st, idx)
            
        return res
        