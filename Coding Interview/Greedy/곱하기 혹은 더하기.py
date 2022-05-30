n = input() #하나의 문자열로 입력 받음

ans = 0
cnt = 0

for i in range(0, len(n)):
    num = int(n[cnt])
    if ans == 0 or num <= 1:
        ans += num
    else:
        ans *= num
    cnt += 1

print(ans)
