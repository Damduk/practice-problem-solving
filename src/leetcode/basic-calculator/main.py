def make_syntax(str):
    res = list()
    num = ""
    
    res.append('(')
    for c in str:
        if c == ' ':
            continue
        elif c in "-+()":
            if len(num) > 0:
                res.append(num)
                num = ''
            
            res.append(c)
        else:
            num += c
        
    if len(num) > 0:
        res.append(num)
        num = ''
        
    res.append(')')
    
    return res

def subcal(operators, operands):
    sub_operators = list()
    sub_operands = list()
    operation = {
        '+': lambda x,y: x+y,
        '-': lambda x,y: x-y,
    }
    
    sub_operands.append(operands.pop())
    while True:
        t = operators.pop()
        if t == '(':
            break
            
        opr = operands.pop()
        
        sub_operators.append(t)
        sub_operands.append(opr)
        
    while len(sub_operators) > 0:
        t = sub_operators.pop()
        
        opr1, opr2 = sub_operands.pop(), sub_operands.pop()
        res = operation[t](opr1, opr2)
        
        sub_operands.append(res)
    
    if len(sub_operands) > 0:
        operands.append(sub_operands[0])


class Solution:
    def calculate(self, s: str) -> int:
        syntax = make_syntax(s)
        
        operators = list()
        operands = list()
        
        m = 1
        for idx in range(len(syntax)):
            item = syntax[idx]
            prev = syntax[idx - 1 if idx > 0 else 0]
            
            if item in '+(':
                operators.append(item)
            elif item == '-':
                if idx == 0 or prev == '(':
                    m = -1
                else:
                    operators.append(item)
            elif item == ')':
                subcal(operators, operands)
            else:
                num = int(item) * m
                m = 1
                operands.append(num)
                
        return operands[0]
        