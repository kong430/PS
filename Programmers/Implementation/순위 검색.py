'''
1. cpp / java / python
2. backend / frontend
3. junior / senior
4. chicken / pizza
조건 선택 -> 조건 만족 사람 중 x점 이상인 사람 몇 명?
(모두 패스인 조건은 '-')
'''
from itertools import combinations
from bisect import bisect_left

def solution(info, query):
    dic = {}
    # info 쿼리로 만들 수 있는 모든 경우의 수 2^4
    # key: info 쿼리 모든 경우의 수에 대한 문자열, value: score list
    for i in info:
        cons = i.split(' ')
        condition = cons[:-1]
        score = int(cons[-1])
        for j in range(5):
            for k in combinations(condition, j):
                nkey = ''.join(k)
                if nkey in dic:
                    dic[nkey].append(score)
                else:
                    dic[nkey]=[score]
    
    # 이분 탐색 위해 오름차순 sort
    for k in dic.keys():
        dic[k].sort()
                    
    answer = []
    for q in query:
        a, b, c, d = q.split(' and ')
        d, score = d.split(' ')
        score = int(score)
        s = a+b+c+d
        
        # -는 최대 4개 포함
        for i in range(4):
            s = s.replace('-', '')
        
        if not s in dic:
            answer.append(0)
            continue
        cnt = len(dic[s]) - bisect_left(dic[s], score)
        answer.append(cnt)

    return answer
