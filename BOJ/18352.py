from collections import deque

n, m, k, x = map(int, input().split())

# 인접 리스트
ad_list = [[] for _ in range(0, n+1)]
for i in range(m):
    s, e = map(int, input().split())
    ad_list[s].append(e)

# x에서 x는 0, 인접하지 않으면 1e9로 초기화
dist = [1e9]*(n+1)
dist[x] = 0

def bfs(x):
    global dist
    global ad_list
    
    q = deque([x])
    while q:
        now = q.popleft()
        for next in ad_list[now]:
            # 한 번도 방문하지 않은 노드라면
            if dist[next] == 1e9:
                dist[next] = dist[now] + 1
                q.append(next)
              
bfs(x)
if any(d==k for d in dist):
    for i in range(len(dist)):
        if dist[i] == k:
            print(i)
else:
    print(-1)
