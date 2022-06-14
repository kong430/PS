'''
올바른 괄호열
    ()
    []
    x가 올바른 괄호열일 때, (x)나 [x]도 올바른 괄호열
    x와 y가 올바른 괄호열이면, xy도 올바른 괄호열
    
어떤 올바른 괄호열 x에 대해서, 괄호값 값(x)를 아래와 같이 정의
    1. 값 () = 2
    2. 값 [] = 3
    3. 값 (x) = 2 * 값 x
    4. 값 [x] = 3 * 값 x
    5. 값 xy = 값 x + 값 y
'''
s = input()
length = len(s)
stack = []
tmp = 1
answer = 0

for i in range(length):
    b = s[i]
    if b == '(':
        tmp *= 2
        stack.append(b)
    elif b == '[':
        tmp *= 3
        stack.append(b)
    elif b == ')':
        if not stack or stack[-1] == '[':
            answer = 0
            break
        if s[i-1] == '(':
            answer += tmp
        tmp //= 2
        stack.pop()  
    else:
        if not stack or stack[-1] == '(':
            answer = 0
            break
        if s[i-1] == '[':
            answer += tmp
        tmp //= 3
        stack.pop() 

if stack:
    answer = 0
    
print(answer)
