//P.92 큰 수의 법칙

n, m, k = map(int, input().split())
data = list(map(int, input().split()))

data.sort(reverse=True)
first = data[0]
second = data[1]

ans = first * (m - (m % k)) + second * (m % k)
    
print(ans)
