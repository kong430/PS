from itertools import combinations

n, m = map(int, input().split())
house, chicken = [], []

for i in range(n):
    row = list(map(int, input().split()))
    for j in range(n):
        # 모든 집의 좌표와 치킨 거리 리스트 / 치킨집의 좌표 저장
        if row[j] == 1:
            house.append((i, j))
        elif row[j] == 2:
            chicken.append((i, j))

# 치킨 집 m개 고르는 조합 리스트
candi = list(combinations(chicken, m))

# 특정 조합일 때, 모든 집 돌면서 최솟값 갱신
Min = 1e9
for c in candi:
    sum = 0
    for h in house:
        dist = 1e9
        for ck in c:
            if abs(ck[0]-h[0]) + abs(ck[1]-h[1]) < dist:
                dist = abs(ck[0]-h[0]) + abs(ck[1]-h[1])
        sum += dist
    Min = min(Min, sum)

print(Min)
