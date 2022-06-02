# import heapq
from heapq import heappush, heappop

def solution(food_times, k):
		# 방송 중단 전 음식을 다 먹는 경우
    if sum(food_times) <= k:
        return -1
    
		# min heap에 삽입
    pq = []
    for i in range(len(food_times)):
        heappush(pq, (food_times[i], i+1))
        
    cnt = len(food_times) # 남은 음식 개수
    time = 0 # 이전에 다 먹은 음식을 다 먹는 데 걸렸던 시간

		# 현재 음식(가장 적게 걸리는 음식)을 0으로 만들 수 있냐 
    while (pq[0][0] - time) * cnt < k:
        k -= (pq[0][0] - time) * cnt
        time += (pq[0][0] - time)
        cnt -= 1
        heappop(pq)
        
    result = sorted(pq, key=lambda x: x[1])
    return result[k % cnt][1]
