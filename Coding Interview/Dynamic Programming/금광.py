t = int(input())

while t:
    t -= 1
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    
    dp = []
    idx = 0
    for i in range(n):
        dp.append(arr[idx:idx+m])
        idx += m
 
    Max = 0
    for j in range(1, m):
        for i in range(n):
            if i==0:
                dp[i][j] = max([dp[i][j-1], dp[i+1][j-1]])+dp[i][j]
            elif i==n-1:
                dp[i][j] = max([dp[i-1][j-1], dp[i][j-1]])+dp[i][j]
            else:
                dp[i][j] = max([dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1]])+dp[i][j]
            Max = max(Max, dp[i][j])

    print(Max)
