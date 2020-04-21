class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def bsearch_min(arr, l, r):      
            if l > r: 
                return -1
            if l == r:
                return l
            
            mid = (l + r) // 2
            if arr[mid] < arr[r]:
                return bsearch_min(arr, l, mid)
            else:
                return bsearch_min(arr, mid + 1, r)
            
        def bsearch(arr, t, l, r):
            if l > r:
                return -1
            
            mid = (l + r) // 2
            if arr[mid] == t:
                return mid
            elif arr[mid] < t:
                return bsearch(arr, t, mid + 1, r)
            else:
                return bsearch(arr, t, l, mid - 1)
            
        min_idx = bsearch_min(nums, 0, len(nums) - 1)
        if min_idx == -1:
            return -1
        
        return max(
            bsearch(nums, target, 0, min_idx - 1),
            bsearch(nums, target, min_idx, len(nums) - 1),
        )