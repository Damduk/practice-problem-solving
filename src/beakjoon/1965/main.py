def main():
    N = int(input())
    A = [int(x) for x in input().split()]
    DP = [0 for _ in range(N)]
    DP[0] = 1
    
    res = 1
    for i in range(1, N):
        DP[i] = 1
        
        for j in range(i):
            if A[i] > A[j] and DP[j] + 1 > DP[i]:
                DP[i] = DP[j] + 1
        
        res = max(res, DP[i])
    
    print(res)
    
main()
