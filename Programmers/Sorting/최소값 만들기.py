def solution(A,B):
    A.sort(reverse=True)
    B.sort()
    
    answer = 0
    for i in range(len(A)):
        answer += A[i]*B[i]
    return answer
  
'''
def solution(A,B):
    return sum(a*b for a, b in zip(sorted(A, reverse=True), sorted(B)))
'''
