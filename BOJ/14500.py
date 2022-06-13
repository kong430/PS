n, m = map(int, input().split())
nmap = []
for _ in range(n):
    nmap.append(list(map(int, input().split())))

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

visited = [[0]*m for _ in range(n)]

Max = -1e9
def dfs(start, total, cnt):
    global Max
    global visited
    
    if cnt == 4:
        Max = max(Max, total)
        return
    
    for i in range(4):
        nx = start[0] + dx[i]
        ny = start[1] + dy[i]
        if nx<0 or nx>=n or ny<0 or ny>=m:
            continue
        if visited[nx][ny]:
            continue
        else:
            '''
            'ㅗ', 'ㅏ', 'ㅜ', 'ㅓ' 형태를 만들기 위함
            깊이 3인 지점 방문 처리는 하되 start 지점은 유지
            '''
            if cnt == 2:
                visited[nx][ny] = 1 
                dfs(start, total+nmap[nx][ny], cnt+1)
                visited[nx][ny] = 1
            visited[nx][ny] = 1
            dfs((nx, ny), total+nmap[nx][ny], cnt+1)
            visited[nx][ny] = 0
        
for i in range(n):
    for j in range(m):
        visited[i][j] = 1
        dfs((i, j), nmap[i][j], 1)
        visited[i][j] = 0
        
print(Max)
