'''
피로도 = 0이상의 정수
던전마다 아래 두가지가 주어짐
    최소 필요 피로도: 탐험 시작하기 위해 필요한 최소한의 피로도
    소모 피로도: 탐험한 후 소모
한 유저가 최대 개수의 던전을 탐험하고 싶다
    k: 현재 피로도
최대 던전 수 return
-> 순서 바꿔서 최대 개수 탐험하도록
-> 던전의 최대 개수는 8이므로, len(dun) permutations (1~len(dun))까지 돌며 최댓값 갱신
'''
from itertools import permutations

def solution(k, dungeons):
    # 1~len(dun)개 뽑는 순열
    Max = -1e9
    
    for i in range(1, len(dungeons)+1):
        # i개 탐험하는 특정 후보
        for duns in permutations(dungeons, i):
            chk = 1
            tmp_k = k
            for dun in duns:
                if tmp_k>=dun[0]:
                    tmp_k -= dun[1]
                else:
                    chk = 0
            if chk:
                Max = max(Max, i)
                break
    
    return Max
