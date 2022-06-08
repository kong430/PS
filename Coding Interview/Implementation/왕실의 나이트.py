str = input()
x = int(ord(str[0])) - 97
y = int(str[1]) - 1

steps = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]

answer = 0
for step in steps:
    nx = x + step[0]
    ny = y + step[1]
    if nx >= 0 and nx <= 7 and ny >= 0 and ny <= 7:
        answer += 1

print(answer)
