from collections import deque

def is_balanced(s):
    cnt1, cnt2 = 0, 0
    for i in range(len(s)):
        if s[i] == '(':
            cnt1 += 1
        elif s[i] == ')':
            cnt2 += 1
    return cnt1 == cnt2
    
def is_correct(s):
    q = deque()
    if len(s) == 0:
        return True
    if s[0] == ')':
        return False
    else:
        for i in range(len(s)):
            if s[i] == '(':
                q.append(0)
            elif s[i] == ')' and q:
                q.popleft()
            else:
                return False
    return True
            
def transform(w):
    if len(w) == 0:
        return ''
    u, v = '', ''
    for i in range(1, len(w)+1):
        if is_balanced(w[:i]) and is_balanced(w[i:]):
            u = w[:i]
            v = w[i:]
            break
    
    if is_correct(u):
        return u+transform(v)
    else:
        new = '(' + transform(v) + ')'
        for i in range(1, len(u)-1):
            new = new + ('(' if u[i] ==')' else ')')
        return new
                
def solution(p):
    answer = ''
    if is_correct(p):
        return p
    return transform(p)
