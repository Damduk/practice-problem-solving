def main():
    tmp = set()
    res = []

    N, M = [int(x) for x in input().split()]
    for _ in range(N):
       tmp.add(input())
    
    for _ in range(M):
        c = input()
        if c in tmp:
            res.append(c)
            
    res.sort()
    
    print(len(res))
    for item in res:
        print(item)
    
main()
