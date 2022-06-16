'''
2x1 크기의 로봇을 움직여 (N, N)까지 이동시킬 것임
로봇이 차지하는 두 칸 중 어느 한 칸이라도 (N, N)에 도착하면 됨, 최소시간 출력
지도
    NxN, 0과 1로 이루어짐
    가장 왼쪽 상단이 (1, 1)
    0은 빈칸
    1은 벽
로봇
    90도씩 회전 가능
    단, 회전 영역에 벽이 있다면 회전 불가능
시간
    회전하는데 1초
    한칸 이동하는데 1초
항상 목적지에 도착 가능, 처음에는 (1, 1), (1, 2)에 위치
'''
from collections import deque

# 현재 위치로부터 이동 가능한 모든 위치 반환
def get_next_pos(now, board):
    next_pos = []
    now = list(now)
    x0, y0, x1, y1 = now[0][0], now[0][1], now[1][0], now[1][1]
    
    # 이동
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    for i in range(4):
        nx0, ny0, nx1, ny1 = x0+dx[i], y0+dy[i], x1+dx[i], y1+dy[i]
        # 두 칸이 모두 빈칸이라면
        if board[nx0][ny0]==0 and board[nx1][ny1]==0:
            next_pos.append({(nx0, ny0), (nx1, ny1)})
    
    # 회전
    # 현재 가로인 경우
    if x0==x1:
        # 위 or 아래
        for i in [-1, 1]:
            # 두 칸 다 비어있어야 회전 가능
            if board[x0+i][y0]==0 and board[x1+i][y1]==0:
                next_pos.append({(x0, y0), (x0+i, y0)})
                next_pos.append({(x1, y1), (x1+i, y1)})
    
    # 현재 세로인 경우
    if y0==y1:
        # 왼 or 오
        for i in [-1, 1]:
            if board[x0][y0+i]==0 and board[x1][y1+i]==0:
                next_pos.append({(x0, y0), (x0, y0+i)})
                next_pos.append({(x1, y1), (x1, y1+i)})
    
    return next_pos
        
def solution(board):
    n = len(board)
    
    # 경계가 1로 둘러싸인 확장된 board
    expanded_board = [[1]*(n+2) for _ in range(n+2)]
    for i in range(n):
        for j in range(n):
            expanded_board[i+1][j+1] = board[i][j]
            
    q = deque()
    visited = []
    
    now = {(1, 1), (1, 2)} # set으로 처리하여 {(0, 0), (0, 1)}과 {(0, 1), (0, 0)}을 동일시
    q.append((now, 0))
    visited.append(now)

    while q:
        now, sec = q.popleft()
        if (n,n) in now:
            return sec
        for next in get_next_pos(now, expanded_board):
            if next not in visited:
                q.append((next, sec+1))
                visited.append(next)
                
    return 0
