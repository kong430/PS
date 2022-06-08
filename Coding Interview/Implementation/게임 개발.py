n, m= map(int, input().split())
x, y, direction = map(int, input().split())

visited = [[0] * m for _ in range(n)]
visited[x][y] = 1

nmap = []
for i in range(n):
    nmap.append(list(map(int, input().split())))

# 0: 북, 1: 동, 2: 남, 3: 서
# 3->2->1->0->3->2 ...
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def turn_left():
    global direction
    direction -= 1
    if direction == -1:
        direction = 3

count = 1
while True:
    chk = 0
    for i in range(4):
        turn_left()
        nx = x + dx[direction]
        ny = y + dy[direction]
        if nmap[nx][ny] == 0 and visited[nx][ny] == 0:
            visited[nx][ny] = 1
            x = nx
            y = ny
            chk = 1
            count += 1
            break
        else:
            continue
    if chk == 0:
        nx = x-dx[direction]
        ny = y-dy[direction]
        if nmap[nx][ny] == 0:
            x = nx
            y = ny
        else :
            break    
         
print(count)
