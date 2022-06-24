'''
후보키: 속성의 set 중 (1개 이상)
    모든 튜플을 식별 가능하고
    2개 이상이라면 각각은 후보키가 아니어야 함
-> 컬럼이 최대 8개, 1~8개 고르는 속성으로 완탐
'''
from itertools import combinations

def solution(relation):
    # 컬럼 수
    n = len(relation[0])
    all_cols = [i for i in range(n)]
    cks = []
    
    answer = 0
    # i개 조합으로 key 생성
    for i in range(1, n+1):
        # key 형성하는 각 column idx
        for combi in combinations(all_cols, i):
            attrs = []
            for rel in relation:
                attr = [rel[c] for c in combi]
                if attr in attrs:
                    break
                else:
                    attrs .append(attr)
            else:
                for ck in cks:
                    if set(ck).issubset(set(combi)):
                        break
                else:
                    answer += 1
                    cks.append(combi)
    return answer
