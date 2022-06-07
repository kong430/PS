from collections import deque

def solution(people, limit):
    people.sort()
    boat = 0
    
    dq = deque(people)
    
    while dq:
        if len(dq) >= 2:
            if dq[0] + dq[-1] <= limit:
                dq.pop()
                dq.popleft()
                boat += 1
            else:
                dq.pop()
                boat += 1
        else:
            dq.pop()
            boat += 1  
    return boat
