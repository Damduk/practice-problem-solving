def solve(nums):
    sz = len(nums)
    
    s = set()
    for i in range(sz - 1):
        hs = dict()
        for j in range(sz):
            if (i != j):
                hs[nums[j]] = j
                
        for j in range(i + 1, sz):
            t = hs.get(-(nums[i] + nums[j]))
            if t == None:
                continue
                
            if j == t:
                continue
                
            l = [nums[i], nums[j], nums[t]]
            for i in range(2, 0, -1):
            	if (l[i] >= l[i - 1]):
            		break
            	print('swap ', l[i], l[i - 1])
            	l[i],l[i-1]=l[i-1],l[i]
                print('after',l[i],l[i - 1])

            s.add(tuple(l))    

    return list(map(lambda x: list(x), s))

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        return solve(nums)