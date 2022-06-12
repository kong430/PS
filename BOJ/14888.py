import math

n = int(input())
nums = list(map(int, input().split()))
pl, sub, mul, div = map(int, input().split())

Min, Max = 1e9, -1e9

def dfs(result, idx, p, s, m, d):
    global Min, Max
    
    if p<0 or s<0 or m<0 or d<0:
        return
    if idx == n:
        Min = min(Min, result)
        Max = max(Max, result)
        return

    dfs(result+nums[idx], idx+1, p-1, s, m, d)
    dfs(result-nums[idx], idx+1, p, s-1, m, d)
    dfs(result*nums[idx], idx+1, p, s, m-1, d)
    dfs(result//nums[idx] if result>0 else -(abs(result)//nums[idx]), idx+1, p, s, m, d-1)
    
dfs(nums[0], 1, pl, sub, mul, div)
print(Max, Min)
