# Counter
'''
코스: 최소 2가지 이상의 단품으로 구성됨.
    단, 최소 2명 이상으로부터 주문된 메뉴 조합
course에 있는 개수 조합으로만
'''
from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []
    for c in course:
        order_combi = []
        for o in orders:
            for combi in combinations(o, c):
                order_combi.append(''.join(sorted(combi)))
        order_cnt = Counter(order_combi).most_common()

        Max = 0
        for o in order_cnt:
            Max = max(Max, o[1])
        if Max>=2:
            for o in order_cnt:
                if o[1]==Max:
                    answer.append(o[0])
    
    return sorted(answer)
  
'''
# dictionary
from itertools import combinations

def solution(orders, course):
    dic = {}
    for c in course:
        for o in orders:
            for combi in combinations(list(o), c):
                combi = sorted(combi)
                sc = ''.join(combi)
                if sc in dic:
                    dic[sc] += 1
                else:
                    dic[sc] = 1
    
    dic = dict(sorted(dic.items(), key=lambda x:(len(x[0]), x[1], x[0]), reverse=True))
    
    answer = []
    for c in course[::-1]:
        Max = -1e9
        for item in dic.items():
            if len(item[0])==c and item[1]>=2 and item[1]>=Max:
                answer.append(item[0])
                Max = item[1]
    
    return sorted(answer)
  '''
