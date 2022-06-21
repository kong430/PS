'''
모든 음식의 스코빌 지수를 k 이상으로
섞은 음식의 스코빌 지수 = 젤 안매운애 + 젤 안매운거 다음 애
모든 음식을 k 이상으로 만들려면 몇 번을 섞어야 하나?
'''
from heapq import heapify, heappush, heappop

def solution(scoville, K):
    heapify(scoville)
    
    cnt = 0
    while len(scoville)>=2 and scoville[1]<K:
        min1 = heappop(scoville)
        min2 = heappop(scoville) * 2
        heappush(scoville, min1+min2)
        cnt += 1
        
    cnt = cnt if heappop(scoville)>=K else -1
    return cnt
