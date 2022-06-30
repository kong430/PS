from heapq import heappush, heappop

def solution(operations):
    maxq = []
    minq = []
    
    for o in operations:
        command, n = o.split(' ')
        if command=='I':
            heappush(maxq, -int(n))
            heappush(minq, int(n))
        elif command=='D' and maxq and minq:
            if n=='-1': # 최솟값 삭제
                heappop(minq)
            else: # 최댓값 삭제
                heappop(maxq)
        if not maxq or not minq:
            maxq = []
            minq = []
    
    answer = []
    while maxq:
        top = -heappop(maxq)
        if top in minq:
            answer.append(top)
            break
    while minq:
        top = heappop(minq)
        if -top in maxq:
            answer.append(top)
            break

    return answer if answer else [0, 0]
