n, m = map(int, input().split())
arr = []
for i in range(n):
    arr.append(int(input()))

dp = [10001]*(m+1)

dp[0] = 0
for i in range(n):
    for j in range(arr[i], m+1):
        dp[j] = min(dp[j], dp[j-arr[i]]+1)
        
print(dp[m] if dp[m] != 10001 else -1)
