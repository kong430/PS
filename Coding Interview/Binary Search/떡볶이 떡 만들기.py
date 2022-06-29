n, m = map(int, input().split())
ddok = list(map(int, input().split()))

left = 0
right= max(ddok)

Max = left
while left<=right:
    mid = (left+right)//2
    total = 0
    for d in ddok:
        total += d-mid if d-mid>0 else 0
    # 더 자르기
    if total<m:
        right = mid-1
    # 덜 자르기
    else:
        Max = max(Max, mid) # 최대한 덜 잘라서 적어도 m개
        left = mid+1
 
print(Max)
