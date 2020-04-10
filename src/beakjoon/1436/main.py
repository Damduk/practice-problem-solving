def main():
    N = int(input())
    
    n = 666
    idx = 0
    while True:
        s = str(n)
        
        i = s.find('666')
        if i != -1:
            idx += 1
            if idx == N:
                print(s)
                return
        
        n += 1

main()
