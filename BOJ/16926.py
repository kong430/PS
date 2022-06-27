import sys

n, m, r = map(int, input().split())
nmap = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

new_map = [item[:] for item in nmap]

while r:
    r -= 1
    for k in range(min(n, m)//2):
        # 좌
        for i in range(k+1, m-k):
            new_map[k][i-1] = nmap[k][i]
        # 하
        for i in range(k, n-k-1):
            new_map[i+1][k] = nmap[i][k]
        # 우
        for i in range(k, m-k-1):
            new_map[n-k-1][i+1] = nmap[n-k-1][i]
        # 상
        for i in range(k+1, n-k):
            new_map[i-1][m-k-1] = nmap[i][m-k-1]
    nmap = [item[:] for item in new_map]
    
for i in range(n):
    for j in range(m):
        print(new_map[i][j], end=' ')
    print()
