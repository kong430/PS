from heapq import heappush
from heapq import heappop

n = int(input())
times = [tuple(map(int, input().split())) for _ in range(n)]

times.sort(key=lambda x: (x[0]))

pq = []
for time in times:
    if pq and pq[0] <= time[0]:
        heappop(pq)
    heappush(pq, time[1])
            
print(len(pq))
