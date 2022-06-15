'''
NxN map
선생님 or 학생 or 장애물이 위치할 수 있음
선생님 -> 상하좌우 4방향으로 감시 진행
    장애물 뒷편에 숨은 학생은 볼 수 없음
    아무리 멀리 있어도 장애물만 없으면 볼 수 있음
T: 선생님
S: 학생
O: 장애물
X: 빈 칸
3개의 장애물 설치 후,
선생님이 볼 수 있는 학생이 0명인가? -> YES / NO 출력

-> 선생님과 일직선상에 있는 학생만 볼 수 있음
-> bfs로 탐색
'''
from itertools import combinations

n = int(input())
nmap = [list(input().split()) for _ in range(n)]

# 세 지점에 장애물 설치
def set_ob(points):
    for point in points:
        o_points.append((point[0], point[1]))
        nmap[point[0]][point[1]] = 'O'
        
def remove_ob(points):
    global o_points
    
    o_points = []
    for point in points:
        nmap[point[0]][point[1]] = 'X'
        
# T가 S 하나라도 발견 가능하면 True 리턴
def search(t):
    for s in s_points:
        # 같은 y축에 있다면
        if s[0] == t[0]:
            # s가 t보다 오른쪽에 있을 경우 
            if s[1] > t[1]:
                if any(o[0]==s[0] and o[1]<s[1] and t[1]<o[1] for o in o_points):
                    continue
            # 왼쪽
            elif s[1] < t[1]:
                if any(o[0]==s[0] and o[1]>s[1] and t[1]>o[1] for o in o_points):
                    continue
            return True
        elif s[1] == t[1]:
            # s가 t보다 아래에 있을 경우
            if s[0] > t[0]:
                if any(o[1]==s[1] and o[0]<s[0] and t[0]<o[0] for o in o_points):
                    continue
            elif s[0] < t[0]:
                if any(o[1]==s[1] and o[0]>s[0] and o[0]<t[0] for o in o_points):
                    continue
            return True
    return False      
    
x_points = []
t_points = []
s_points = []
o_points = []

for i in range(n):
    for j in range(n):
        if nmap[i][j] == 'T':
            t_points.append((i, j))
        elif nmap[i][j] == 'X':
            x_points.append((i, j))
        elif nmap[i][j] == 'S':
            s_points.append((i, j))
            
# points: 장애물 설치할 세 지점
for points in combinations(x_points, 3):
    set_ob(points)
    chk = 0
    for t in t_points:
        if search(t):
            chk = 1
            break 
    if not chk:
        break
    remove_ob(points)


if not chk:
    print('YES')
else:
    print('NO')
