def solution(priorities, location):
    pris = [(i, prior) for i, prior in enumerate(priorities)]
    
    answer = 1
    while True:
        if len(pris) == 1:
            break
        if any(x[1]>pris[0][1] for x in pris[1:]):
            pris.append(pris[0])
            pris.pop(0)
        else:
            if pris[0][0] == location:
                break
            pris.pop(0)
            answer += 1
            
    return answer
