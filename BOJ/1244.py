'''
1: on, 0: off
남학생: 스위치 번호가 본인 수의 배수이면, toggle
여학생: 스위치 번호가 본인 수와 같으면, 팰린드롬 느낌으로 포함구간 모두 toggle
스위치 상태 1번부터 시작, 사이에 공백, 한 줄에 20개씩 출력
'''
on_off = {0:1, 1:0}

n = int(input()) # 스위치 수
# 1-base로 확장
switches = [0] + list(map(int, input().split()))
m = int(input()) # 학생 수
students = []
for _ in range(m):
    sex, num = map(int, input().split()) # 성별, 수
    students.append((sex, num))

def find_idxs(stu):
    idxs = []
    # 남학생이면
    if stu[0]==1:
        idxs = list(i for i in range(1, n+1) if i%stu[1]==0)
    # 여학생이면
    else:
        idxs = [stu[1]]
        before, after = stu[1]-1, stu[1]+1
        while True:
            if before<1 or after>n:
                break
            if switches[before]!=switches[after]:
                break
            idxs.extend([before, after])
            before -= 1
            after += 1
    return idxs
    
def toggle_switches(sws):
    global switches
    for s in sws:
        switches[s] = on_off[switches[s]]

for s in students:
    idxs = find_idxs(s)
    toggle_switches(idxs)

# idx 위해 확장시켰던 0번째 제거
switches = switches[1:]
while True:
    if len(switches)>20:
        print(' '.join(map(str, switches[:20])))
        switches = switches[20:]
    else:
        print(' '.join(map(str, switches)))
        break
