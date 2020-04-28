class FirstUnique:

    def __init__(self, nums: List[int]):
        self.black = set()
        self.q = dict()
        
        for num in nums:
            if num in self.black:
                continue
            elif num in self.q:
                del self.q[num]
                self.black.add(num)
            else:
                self.q[num] = 1

    def showFirstUnique(self) -> int:
        for num in self.q.keys():
            return num
        
        return -1

    def add(self, value: int) -> None:
        if value in self.black:
            return
        elif value in self.q:
            del self.q[value]
            self.black.add(value)
        else:
            self.q[value] = 1


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)