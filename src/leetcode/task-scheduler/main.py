INF = sys.maxsize

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter = dict()
        mx = 0
        mx_cnt = 0
        for task in tasks:
            counter[task] = counter.get(task, 0) + 1
            if mx == counter[task]:
                mx_cnt += 1
            elif mx < counter[task]:
                mx = counter[task]
                mx_cnt = 1
        
        part_cnt = mx - 1
        part_sz = n - (mx_cnt - 1)
        empty_slots = part_sz * part_cnt
        available_slots = len(tasks) - (mx * mx_cnt)
        idle = max(0, empty_slots - available_slots)
        
        return len(tasks) + idle
            