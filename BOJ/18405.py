'''
nxn 크기의 시험관
특정한 위치에 바이러스 존재할 수 있음. 1~K 중 하나
    모든 바이러스는 1초마다 상하좌우 중 하나로 증식
    단, 번호가 낮은 바이러스부터 먼저 증식
    빈 칸으로만 증식 가능
S초가 지난 후 (X, Y)에 몇 번 바이러스가 존재하는가
    없다면 0 출력
    
(X, Y) -> (X-1, Y-1)
'''
from collections import deque

# k: 바이러스 종류의 최댓값, 최대 1,000
n, k = map(int, input().split())
nmap = [list(map(int, input().split())) for _ in range(n)]
target_s, target_x, target_y = map(int, input().split())

viruses = []
for i in range(n):
    for j in range(n):
        if nmap[i][j] != 0:
            # (바이러스 type, 생긴 시간, x, y)
            viruses.append((nmap[i][j], 0, i, j))
            
viruses.sort()
q = deque(viruses)

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

while q:
    virus, sec, x, y = q.popleft()
    if sec == target_s:
        break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx<0 or nx>=n or ny<0 or ny>=n:
            continue
        if nmap[nx][ny] == 0:
            nmap[nx][ny] = virus
            q.append((virus, sec+1, nx, ny))

print(nmap[target_x-1][target_y-1])   
