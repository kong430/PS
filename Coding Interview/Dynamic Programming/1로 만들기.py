x = int(input())

dp = [0]*30001

for i in range(2, x+1):
    # 1을 뺴는 경우
    dp[i] = dp[i-1]+1
    # 2로 나누어 떨어질 경우
    if i%2==0:
        dp[i] = min(dp[i], dp[i//2]+1)
    # 3으로
    if i%3==0:
        dp[i] = min(dp[i], dp[i//3]+1)
    # 5로
    if i%5==0:
        dp[i] = min(dp[i], dp[i//5]+1)

print(dp[x])
