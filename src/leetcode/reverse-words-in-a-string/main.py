class Solution:
    def reverseWords(self, s: str) -> str:
        arr = list(filter(lambda x: x != '', reversed(s.split(' '))))
        return ' '.join(arr)
        