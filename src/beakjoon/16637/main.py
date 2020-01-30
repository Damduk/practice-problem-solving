ops = {
    '+': lambda x, y: x+y,
    '-': lambda x, y: x-y,
    '*': lambda x, y: x*y,
    '/': lambda x, y: x//y,
}


def popAndCalculate(st):
    while len(st) > 2:
        oprand2, op, oprand1 = st.pop(), st.pop(), st.pop()
        tmp = ops[op](int(oprand1), int(oprand2))
        st.append(tmp)


def calculate(syntax):
    st = []
    nested = False

    for c in syntax:
        if c == '(':
            nested = True
        elif c == ')':
            nested = False
            popAndCalculate(st)
        else:
            st.append(c)
            if nested == False:
                popAndCalculate(st)

    return st[0]


def backtracking(syntax, idx):
    syntax = syntax[:idx-1] + '(' + syntax[idx-1:idx+2] + ')' + syntax[idx+2:]

    res = max(-10000000, calculate(syntax))
    n = min(idx + 5, len(syntax) - 1)
    for next in range(n, len(syntax)):
        if syntax[next] in ops:
            res = max(res, backtracking(syntax, next))

    return res


def main():
    n = int(input())
    syntax = input()

    res = calculate(syntax)
    for i, c in enumerate(syntax):
        if c in ops:
            res = max(res, backtracking(syntax, i))

    print(res)


main()
