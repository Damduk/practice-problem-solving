import queue

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        q = queue.Queue()
        
        copy = list(digits)
        copy[-1] = copy[-1] + 1
        if copy[-1] == 10:
            q.put(len(copy) - 1)
            
        while q.qsize():
            idx = q.get()
            
            copy[idx] = 0
            
            if idx == 0:
                copy = [1] + copy
            else:
                copy[idx - 1] = copy[idx - 1] + 1
                if copy[idx - 1] == 10:
                    q.put(idx - 1)
        
        return copy