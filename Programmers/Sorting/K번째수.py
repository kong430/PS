'''
array를 (i, j, k) i이상 j이하 idx로 자르고, k번째 수 append
1-base
'''
def solution(array, commands):
    answer = []
    for i, j, k in commands:
        tmp = array[i-1:j]
        tmp.sort()
        answer.append(tmp[k-1])
    return answer
