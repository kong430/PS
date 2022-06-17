from itertools import combinations

def get_dist(a, b):
    return abs(a[0]-b[0])+abs(a[1]-b[1])

# 사람 a와 b사이에 거리두기 지켜지고 있는가
def is_ok(a, b, nmap):
    dist = get_dist(a, b)
    if dist==1:
        return False
    if dist==2:
        # a,X,b
        if a[0]==b[0] and nmap[a[0]][a[1]+1]!='X':
            return False
        # (세로) a,X,b
        elif a[1]==b[1] and  nmap[a[0]+1][a[1]]!='X':
            return False
        # 오른쪽 대각선
        elif a[0]+1==b[0] and a[1]+1==b[1]:
            if nmap[a[0]+1][a[1]]!='X' or nmap[a[0]][a[1]+1]!='X':
                return False
        # 왼쪽 대각선
        elif a[0]+1==b[0] and a[1]-1==b[1]:
            if nmap[a[0]][a[1]-1]!='X' or nmap[a[0]+1][a[1]]!='X':
                return False
    return True

def solution(places):
    answer = [] # 결과 담을 배열
                             
    for place in places:
        flag = 0
        all_idxs = []
        for i in range(5):
            for j in range(5):
                if place[i][j] == 'P':
                    all_idxs.append((i, j))
                    
        # 한 명 이하라면 1
        if len(all_idxs)<=1:
            answer.append(1)
            continue
        
        for persons in combinations(all_idxs, 2):
            # a가 b보다 항상 위, 같다면 왼
            persons = sorted(list(persons), key=lambda x:(x[0],x[1]))
            a, b = persons[0], persons[1]
            # 한 쌍이라도 거리두기 지키지 않았으면 해당 테케 실패
            if not is_ok(a,b, place):
                answer.append(0)
                flag = 1
                break
        if not flag:
            answer.append(1)
            
    return answer
