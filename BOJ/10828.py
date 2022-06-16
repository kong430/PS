import sys
n = int(sys.stdin.readline())

stack = []
def npush(su):
    global stack
    stack.append(su)
    
def npop():
    global stack
    if stack:
        print(stack[-1])
        stack = stack[:-1]
    else:
        print(-1)

def nsize():
    global stack
    print(len(stack))

def nempty():
    global stack
    if stack:
        print(0)
    else:
        print(1)
    
def ntop():
    global stack
    if stack:
        print(stack[-1])
    else:
        print(-1)
        
for _ in range(n):
    commands = sys.stdin.readline().split()
    if commands[0]=='push':
        npush(commands[1])
    elif commands[0]=='pop':
        npop()
    elif commands[0]=='size':
        nsize()
    elif commands[0]=='empty':
        nempty()
    elif commands[0]=='top':
        ntop()
