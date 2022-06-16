from collections import deque

n = int(input())

# stack에 어디까지 들어갔었나
idx = 0
stack = []

op = []
for _ in range(n):
    su = int(input())
    while idx<su:
        idx += 1
        stack.append(idx)
        op.append('+')
    if stack[-1]==su:
        stack.pop()
        op.append('-')
    else:
        op = []
        break

if not op:
    print('NO')
else:
    for i in op:
        print(i)
