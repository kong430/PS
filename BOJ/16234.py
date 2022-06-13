from collections import deque

n, l, r = map(int, input().split())
# 인구 수
nmap = []
for i in range(n):
    nmap.append(list(map(int, input().split())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# start와 연합 가능한 국가 모두 return
def bfs(nmap, visited, start):
    nations = []
    
    q = deque([start])
    visited[start[0]][start[1]] = 1
    nations.append((start[0], start[1]))
    
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx<0 or nx>=n or ny<0 or ny>=n:
                continue
            if visited[nx][ny]:
                continue
            diff = abs(nmap[nx][ny] - nmap[x][y])
            if diff<=r and diff>=l:   
                q.append((nx, ny))
                visited[nx][ny] = 1
                nations.append((nx, ny))
                
    return nations

day = 0
while True:
    chk = 0
    visited = [[0]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                nations = bfs(nmap, visited, (i, j))
                # 2개 이상 국가가 연합했다면 인구 이동

                if len(nations) != 1:
                    chk = 1
                    total = sum(nmap[i][j] for i,j in nations)
                    for x, y in nations:
                        nmap[x][y] = total // len(nations)
                        
    # 인구 이동이 일어나지 않았다면 종료                  
    if not chk:
        break
    else: 
        day += 1
        
print(day)
