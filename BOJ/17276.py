'''
크기 nxn인 2차원 배열 (n은 홀수)
배열을 45도 의 배수만큼 시계 or 반시계로 돌릴거다
    시계 방향 45도면
        1. (x, x) 좌표를 (x, (n+1)/2)로 옮김
        2. 가운데 열 (x, (n+1)/2)를 (x, n-x+1)로 옮김
        3. (x, n-x+1) 를 ((n+1)/2, n-x+1)로 옮김
        4. ((n+1)/2, y)를 (y, y)로 옮김
출력: 결과 2차원 배열
'''

# (45도 돌 횟수, 원본 배열)
def rotate(cnt, nmap):
    n = len(nmap)
    mid = (n+1)//2-1
    
    original_map = []
    for _ in range(n):
        original_map = [item[:] for item in nmap]
    new_map = []
    
    # cnt번만큼 시계방향으로 회전
    while cnt:
        new_map = []
        for _ in range(n):
            new_map = [item[:] for item in original_map]
        for i in range(n):
            for j in range(n):
                if i==j:
                    new_map[i][mid] = original_map[i][j]
                if j==mid:
                    new_map[i][n-i-1] = original_map[i][j]
                if j==(n-i-1):
                    new_map[mid][j] = original_map[i][j]
                if i==mid:
                    new_map[j][j] = original_map[i][j]
        for _ in range(n):
            original_map = [item[:] for item in new_map]
        cnt -= 1
        
    return new_map
    

t = int(input())
while t:
    n, d = map(int, input().split())
    nmap = [[0]*n for _ in range(n)]
    nmap = [list(map(int, input().split())) for _ in range(n)]
    result = []
    # 돌지 않아도 될 경우
    if d==0 or d==360 or d==-360:
        result = nmap
    elif d>0:
        result = rotate(d//45, nmap)
    else:
        result = rotate((360-abs(d))//45, nmap)
    for i in range(n):
        print(' '.join(list(str(num) for num in result[i])))
    t -= 1
