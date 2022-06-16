n = int(input())
exp = input()
arr = [int(input()) for _ in range(n)]

stack = []
for c in exp:
    if c.isalpha():
        stack.append(arr[ord(c)-ord('A')])
    else:
        b = stack.pop()
        a = stack.pop()
        if c=='+':
            stack.append(a+b)
        elif c=='-':
            stack.append(a-b)
        elif c=='/':
            stack.append(a/b)
        elif c=='*':
            stack.append(a*b)

print(f"{stack.pop():.2f}")
