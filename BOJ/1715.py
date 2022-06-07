from heapq import heapify
from heapq import heappush
from heapq import heappop

n = int(input())
cards = [int(input()) for _ in range(n)]

heapify(cards)

answer = 0
while len(cards) > 1:
    a = heappop(cards)
    b = heappop(cards)
    heappush(cards, a+b)
    answer += a+b

print(answer)
