n = int(input())
k = int(input())

# 1 base: (1,1) ~(n,n)
nmap = [[0] * (n+1) for _ in range(n+1)]

for _ in range(k):
    a, b = map(int, input().split())
    nmap[a][b] = 1
    
l = int(input())

turns = []
for _ in range(l):
    a, b = input().split()
    turns.append((int(a), b))

# 처음에는 오른쪽을 보고 있음, 시계 방향 기준, 우->하->좌->상
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
exists = [(1, 1)]
head = (1, 1)
direction = 0

def change_direction(dir):
    global direction
    if dir == 'D':
        direction = (direction + 1) % 4
    else:
        direction = (direction - 1) % 4

time = 1
while True:
    nx = head[0] + dx[direction]
    ny = head[1] + dy[direction]
    
    # 머리 이동해야 할 좌표가 맵을 벗어날 경우 중단
    if nx > n or nx < 1 or ny > n or ny < 1:
        break
    # 머리 이동해야 할 좌표가 몸에 부딪히는 경우라면 중단
    if (nx, ny) in exists:
        break
    
    # 머리 이동
    head = (nx, ny)
    
    exists.append(head)
    if nmap[nx][ny] == 0:
        del exists[0]
    else:
        nmap[nx][ny] = 0
    
    if turns and turns[0][0] == time:
        change_direction(turns[0][1])
        del turns[0]
    
    time += 1
    
print(time)
