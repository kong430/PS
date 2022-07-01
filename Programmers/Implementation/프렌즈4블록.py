'''
블럭은 2x2 단위로 지워짐
지워지는 블럭은 겹칠 수 있음
블럭의 종류는 R, N, A, F, N, T, J, C
지우고 나서 빈 칸은 '1'로 바꿔놓자
'''

dx = [1, 1, 0]
dy = [0, 1, 1]

# 가장 왼쪽 위 블럭 기준으로
def check(x, y, board, m, n):
    for i in range(3):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx>=m or ny>=n:
            return False
        if board[nx][ny] != board[x][y]:
            return False
    return True
    
def solution(m, n, board):    
    for i in range(len(board)):
        board[i] = list(board[i])
    
    answer = 0
    while True:
        # pop 되는 지 확인
        removes = [[0]*n for _ in range(m)]
        chk = 0
        for i in range(m):
            for j in range(n):
                # 왼쪽 위 기준으로 pop 가능한지 확인
                if board[i][j] != '1' and check(i, j, board, m, n):
                    chk = 1
                    removes[i][j] = 1
                    for k in range(3):
                        nx = i + dx[k]
                        ny = j + dy[k]
                        removes[nx][ny] = 1
                        
        # 지울 게 없다면 종료
        if not chk:
            break
        
        # pop
        for i in range(m):
            for j in range(n):
                if removes[i][j]:
                    board[i][j] = '1'
                    answer += 1
        
        # 떨어뜨리기
        for i in range(n):
            tmp = [] # 1이 아닌 것들만 담기
            for j in range(m):
                if board[j][i] != '1':
                    tmp.append(board[j][i])
            idx = 0
            for j in range(m-len(tmp), m):
                board[j][i] = tmp[idx]
                idx += 1
            for j in range(0, m-len(tmp)):
                board[j][i] = '1'
                
    return answer
