# 시계 방향으로 회전
def rotate_map(key):
    ones = []
    for i in range(len(key)):
        for j in range(len(key)):
            if key[i][j] == 1:
                ones.append([j, len(key) - i - 1])
    new_map = [[0] * len(key) for _ in range(len(key))]
    for one in ones:
        new_map[one[0]][one[1]] = 1
    return new_map

def check_val(n, lock):
    for i in range(n, n*2):
        for j in range(n, n*2):
            if lock[i][j] != 1:
                return False
    return True

def solution(key, lock):
    n_key = len(key)
    n_lock = len(lock)
    
    # 상하좌우 모두 n_lock만큼 확장
    new_lock = [[0] * (n_lock)*3 for _ in range(n_lock*3)]
    for i in range(n_lock):
        for j in range(n_lock):
            new_lock[i+n_lock][j+n_lock] = lock[i][j]
    
    # lock 내에서 key를 이동시킴
    for i in range(n_lock*2):
        for j in range(n_lock*2):
            # 제자리에서 회전
            for _ in range(4):
                key = rotate_map(key)
                # 자물쇠 있는 부분 끼워넣기
                for a in range(n_key):
                    for b in range(n_key):
                        new_lock[i+a][j+b] += key[a][b]
                # 각 칸이 모두 1이면 valid
                if check_val(n_lock, new_lock):
                    return True
                # 안 되면 빼기
                for a in range(n_key):
                    for b in range(n_key):
                        new_lock[i+a][j+b] -= key[a][b]
    return False
