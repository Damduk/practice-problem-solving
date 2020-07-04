class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        copy = list(cells)
        sz = len(copy)
        
        # About cache
        history = [0]
        d = dict()
        
        for l in range(N): 
            h = str(copy)
            if exist := d.get(h):
                subset = len(history) - exist
                rem = (N - (exist - 1)) % subset
                
                return history[exist + rem]
            
            snap = list(copy)
            d[h] = len(history)
            
            history.append(snap)
            for i in range(1, sz - 1):
                left = snap[i - 1]
                right = snap[i + 1]
                
                copy[i] = 1 if left == right else 0
            
            copy[0] = copy[sz - 1] = 0
            
        return copy