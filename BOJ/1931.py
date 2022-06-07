n = int(input())
times = [tuple(map(int, input().split())) for _ in range(n)]
    
times.sort(key=lambda x: (x[1], x[0]))

curr = 0
cnt = 0

for time in times:
    if curr <= time[0]:
        cnt += 1
        curr = time[1]
        
print(cnt)
