from bisect import bisect_left

def solution(citations):
    citations.sort()
    answer = 0
    
    for i in range(citations[len(citations) - 1]):
        if len(citations) - bisect_left(citations, i) >= i:
            answer = max(answer, i)
    return answer
