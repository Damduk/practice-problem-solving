def main():
    c = 0
    
    A = [[] for _ in range(5)]
    for i in range(5):
        A[i] = list(input())
        c = max(c, len(A[i]))
        
    for i in range(c):
        for j in range(5):
            sz = len(A[j])
            if sz <= i:
                continue
                
            print(A[j][i], end='')
        
main()
