n, m = map(int, input().split())
r, c, d = map(int, input().split())
nmap = []
for _ in range(n):
    nmap.append(list(map(int, input().split())))
    
# 북, 동, 남, 서
# 왼쪽으로 회전: 3 -> 2 -> 1 -> 0
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

visited = [[0]*m for _ in range(n)]
x = r
y = c
visited[x][y] = 1

def turn_left():
    global d
    d = (d-1 if d else 3)

cnt = 1
while True:
    chk = 0
    # 왼쪽으로 돌며 다음 칸 체크
    for _ in range(4):
        turn_left()
        nx = x + dx[d]
        ny = y + dy[d]
        if nmap[nx][ny]:
            continue
        if visited[nx][ny]:
            continue
        else:
            visited[nx][ny] = 1
            cnt += 1
            x = nx
            y = ny
            chk = 1
            break
        
    # 다 돌아도 청소할 곳이 없다면
    if not chk:
        nx = x-dx[d]
        ny = y-dy[d]
        # 뒤로 갈 수 있다면 가기
        if nmap[nx][ny]:
            break
        else:
            x = nx
            y = ny

print(cnt)
