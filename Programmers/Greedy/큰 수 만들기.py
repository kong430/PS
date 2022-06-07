def solution(number, k):
    stack = []
    idx = 0
    
    while idx<len(number) and k>0:
        if len(stack) != 0 and stack[-1] < number[idx]:
            stack.pop()
            k -= 1
        else:
            stack.append(number[idx])
            idx += 1
        
    answer = "".join(stack) + number[idx:]
    
    # 기존 수가 내림차순으로 정렬되어 있을 경우, 위 반복문에서 k개 처리 불가
    if (k != 0):
        answer = answer[:-k]
        
    return answer
