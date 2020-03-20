class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        
        res = []
        
        form = []
        for item in intervals:
            if len(form) == 0:
                form = [item[0], item[1]]
            else:
                if form[0] == item[0] or form[1] >= item[0]:
                    form[1] = max(form[1], item[1])
                else:
                    res.append(form)
                    form = [item[0], item[1]]
        
        if len(form) == 2:
            res.append(form)
        
        return res
        