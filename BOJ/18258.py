import sys
from collections import deque
n = int(input())

queue = deque()
for _ in range(n):
    commands = sys.stdin.readline().split()
    if commands[0]=='push':
        queue.append(commands[1])
    elif commands[0]=='pop':
        if queue:
            print(queue[0])
            queue.popleft()
        else:
            print(-1)
    elif commands[0]=='size':
        print(len(queue))
    elif commands[0]=='empty':
        if queue:
            print(0)
        else:
            print(1)
    elif commands[0]=='front':
        if queue:
            print(queue[0])
        else:
            print(-1)
    elif commands[0]=='back':
        if queue:
            print(queue[len(queue)-1])
        else:
            print(-1)
