IDLE = 0
BUY = 1
SELL = 2

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        sz = len(prices)
        s0, s1, s2 = [0 for _ in range(sz)], [0 for _ in range(sz)], [0 for _ in range(sz)]
        s0[0], s1[0], s2[0] = 0, -prices[0], -sys.maxsize
        
        for i in range(1, sz):
            s0[i] = max(s0[i - 1], s2[i - 1])
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i])
            s2[i] = s1[i - 1] + prices[i]
        return max(s0[sz - 1], s2[sz - 1])
        