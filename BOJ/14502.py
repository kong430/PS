from itertools import combinations
from collections import deque

def set_wall(nmap, emptys):
    for empty in emptys:
        # 벽 설치
        nmap[empty[0]][empty[1]] = 1
    return nmap
            
def spread_viruses(nmap, viruses):
    for virus in viruses:
        q = deque([virus])
        while q:
            now = q.popleft()
            for i in range(4):
                nx = now[0] + dx[i]
                ny = now[1] + dy[i]
                if nx < 0 or nx >= n or ny < 0 or ny >= m:
                    continue
                # 빈 칸에 전파
                if nmap[nx][ny] == 0:
                    q.append((nx, ny))
                    nmap[nx][ny] = 2
    return nmap

def cal_area(virus_map):
    cnt = 0
    for i in range(n):
        for j in range(m):
            if virus_map[i][j] == 0:
                cnt += 1
    return cnt

n, m = map(int, input().split())
nmap = []
for i in range(n):
    nmap.append(list(map(int, input().split())))

original_emptys = []
viruses = []
for i in range(n):
    for j in range(m):
        if nmap[i][j] == 0:
            original_emptys.append((i, j))
        elif nmap[i][j] == 2:
            viruses.append((i, j))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

Max = -1e9
for emptys in combinations(original_emptys, 3):
    wall_map = set_wall([item[:] for item in nmap], emptys)
    virus_map = spread_viruses([item[:] for item in wall_map], viruses)
    Max = max(Max, cal_area(virus_map))
print(Max)
