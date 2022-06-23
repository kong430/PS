'''
범위 테두리에 있는 숫자들을 시계방향으로 회전
    왼쪽 위&오른쪽 아래 좌표 주어짐 1-base
각 쿼리마다 회전에 의해 위치가 바뀐 숫자들 중 가장 작은 숫자들을 순서대로 배열에 담아 return
오른쪽으로 회전
'''
def rotate(nmap, x0, y0, x1, y1):
    new_map = [item[:] for item in nmap]
    Min = 1e9
    for i in range(len(nmap)):
        for j in range(len(nmap[0])):
            # 직사각형 범위 밖
            if i<x0 or i>x1 or j<y0 or j>y1:
                continue
            # 직사각형 내부
            if x0<i<x1 and y0<j<y1:
                continue
            # 테두리, 우/하/좌/상
            if i==x0 and j!=y1:
                new_map[i][j+1] = nmap[i][j]
            elif j==y1 and i!=x1:
                new_map[i+1][j] = nmap[i][j]
            elif i==x1 and j!=y0:
                new_map[i][j-1] = nmap[i][j]
            elif j==y0 and i!=x0:
                new_map[i-1][j] = nmap[i][j]
            Min = min(Min, nmap[i][j])
    return new_map, Min

def solution(rows, columns, queries):
    nmap = [[0]*columns for _ in range(rows)]
    num = 1
    for i in range(rows):
        for j in range(columns):
            nmap[i][j] = num
            num += 1
    
    answer = []
    for x0, y0, x1, y1 in queries:
        nmap, Min = rotate(nmap, x0-1, y0-1, x1-1, y1-1)
        answer.append(Min)
    
    return answer
