import sys
n = int(input())

def is_v(ss):
    stack = []
    for s in ss:
        if s=='(':
            stack.append(0)
        else:
            if stack:
                stack.pop()
            else:
                return False
    if stack:
        return False
    return True
        
for _ in range(n):
    s = sys.stdin.readline().rstrip()
    if is_v(s):
        print('YES')
    else:
        print('NO')
