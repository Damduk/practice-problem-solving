# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        def search(l, r):
            mid = (l + r) // 2
            midv = isBadVersion(mid)
            if midv and (mid == 0 or not isBadVersion(mid - 1)):
                return mid
            elif midv:
                return search(l, mid)
            else:
                return search(mid, r)
            
        return search(0, n + 1)
        