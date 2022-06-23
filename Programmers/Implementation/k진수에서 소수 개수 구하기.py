def transform(n, k):
    su = ''
    while n:
        su = str(n % k) + su
        n = n // k
    return su
        
def is_prime_number(x):
    if x < 2:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

def solution(n, k):
    cnt = 0
    num = transform(n, k)
    for su in num.split('0'):
        if su=='':
            continue
        if is_prime_number(int(su)):
            cnt += 1
    return cnt
