class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        h = (hour % 12 * 30) + (minutes / 60 * 30)
        m = minutes * 6
        
        angle = abs(m - h)
        
        return 360 - angle if angle > 180 else angle