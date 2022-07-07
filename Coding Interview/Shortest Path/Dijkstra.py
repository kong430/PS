import sys
from heapq import heappush, heappop

n, m = map(int, input().split())
start = int(input())

INF = int(1e9)
dist = [INF] * (n+1)
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((b, c)) # a->b의 비용 c

def dijkstra(start):
    q = []
    heappush(q, (0, start)) # 시작노드
    dist[start] = 0 # 시작노드->시작노드 거리 기록
    while q:
        cur_dist, cur_node = heappop(q) # 최단거리 가장 짧은 노드에 대한 정보
        # 현재 노드가 이미 처리되었던 노드라면 무시
        if dist[cur_node] < cur_dist:
            continue
        # 현재 노드와 연결된 다른 인접한 노드들 확인
        for ad_node in graph[cur_node]:
            cost = cur_dist + ad_node[1]
            # 현재 노드를 거쳐서 가는 거리가 더 짧을 경우
            if cost < dist[ad_node[0]]:
                dist[ad_node[0]] = cost
                heappush(q, (cost, ad_node[0]))

dijkstra(start)
for i in range(1, len(dist)):
    if dist[i] == INF:
        print('도달 불가능')
    else:
        print(dist[i])

'''
입력 예시
6 11
1
1 2 2
1 3 5
1 4 1
2 3 3
2 4 2
3 2 3
3 6 5
4 3 3
4 5 1
5 3 1
5 6 2
출력 예시
0
2
3
1
2
4
'''
