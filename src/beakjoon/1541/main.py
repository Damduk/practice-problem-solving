def main():
    expr = input()    
    l = expr.split('-')
    
    res = None
    for e in l:
        sub = e.split('+')
        s = sum(map(lambda x: int(x), sub))
        if res is not None:
            res -= s
        else:
            res = s
    
    print(res if res else 0)
    
main()
