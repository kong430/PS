from itertools import permutations
from collections import deque

def calculate(pri, expression):
    operands = []
    operators = []

    # operator와 operand 각각 리스트에 저장
    num = ''
    for c in expression:
        if c.isdigit():
            num += c
        else:
            operands.append(num)
            num = ''
            operators.append(c)
    operands.append(num)
    
    # 우선순위 높은 연산자부터 idx 찾아 계산
    for p in pri:
        while p in operators:
            i = operators.index(p)
            su = eval(''.join([operands[i], p, operands[i+1]]))
            del operators[i]
            operands = operands[:i] + [str(su)]+ operands[i+2:]
    return abs(int(operands[0]))

def solution(expression):
    Max = -1e9
    for pri in permutations(['+', '-', '*'], 3):
        Max = max(Max,calculate(pri, expression))
    return abs(Max)
