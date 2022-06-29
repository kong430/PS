n, c = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(int(input()))
arr.sort()

left = 1 # 가능한 최소 거리
right = arr[-1] - arr[0] # 가능한 최대 거리
result = 0

while left<=right:
    mid = (left + right)//2 # 공유기 사ㄲ이의 거리의 최소값
    last = arr[0]
    cnt = 1
    # 마지막으로 설치한 지점과 현재 지점 사이의 거리가 mid 이상이면 설치
    for i in range(1, n):
        if arr[i]-last>=mid:
            last = arr[i]
            cnt += 1
    if cnt>=c:
        left = mid+1
        result = mid
    else:
        right = mid-1

print(result)
