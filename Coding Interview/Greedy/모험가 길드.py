//(P.311)

n = int(input())
data = list(map(int, input().split()))

data.sort()
idx = 0
ans = 0

while (idx < len(data)):
    idx += data[idx]
    if (idx < len(data)): ans  += 1

print(ans)
