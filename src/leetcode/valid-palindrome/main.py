class Solution:
    def isPalindrome(self, s: str) -> bool:
        arr = list(filter(lambda e: 'A' <= e <= 'Z' or '0' <= e <= '9', map(lambda e: e.upper(), s)))

        l, r = 0, len(arr) - 1
        while l <= r:
            if arr[l] != arr[r]:
                return False
            
            l += 1
            r -= 1
        
        return True