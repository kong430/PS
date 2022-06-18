from collections import deque

def check(s):
        stack = []
        for c in s:
            if c == '(' or c == '{' or c == '[':
                stack.append(c)
            else:
                if not stack:
                    return False
                x = stack.pop()
                if c == ')' and x != '(':
                    return False
                elif c == ')' and x != '(':
                    return False
                elif c == '}' and x != '{':
                    return False
        return len(stack) == 0
    
def solution(s):
    s = deque(s)
    print(s)
    answer = 0
    for _ in range(len(s)):
        s.rotate(-1)
        if check(s):
            answer += 1
    return answer
