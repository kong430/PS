'''
0~9
10부터는 한 자리씩 끊어서
n진법에서도 한 자리씩 끊어서
'''
def transform(n, x):
    num = ''
    while True:
        a = n%x
        if a>9:
            a = chr(55+a)
        num = str(a) + num
        n = n//x
        if n==0:
            break
    return num
        
def solution(n, t, m, p):
    answer = ''
    su = ''
    for i in range(100001):
        su += transform(i, n)
    
    for i in range(1, m*t+1):
        if m==p:
            if i%m==0:
                answer += su[i-1]
        else:
            if i%m==p:
                answer += su[i-1]

    return answer
