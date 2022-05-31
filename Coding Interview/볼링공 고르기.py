n, m = map(int, input().split())
balls = list(map(int, input().split()))

cnt = 0
for i in range(0, len(balls)):
    for j in range(i+1, len(balls)):
        if balls[i] == balls[j]:
            continue
        cnt += 1
    
print(cnt)
