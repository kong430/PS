n, m = map(int, input().split())
arr = list(map(int, input().split()))

answer = 0
s, e = 0, 0
while s<=e and e<=n:
    nsum = sum(arr[i] for i in range(s, e))
    if nsum==m:
        answer += 1
    if nsum<m:
        e += 1
    elif nsum>=m:
        s += 1
    
print(answer)
