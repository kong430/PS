'''
파일을 확장자별로, 카운트
확장자는 사전순으로 정렬
파일: 파일이름.확장자
'''

n = int(input())
files = [input() for i in range(n)]

dic = {}
for file in files:
    name, ex = file.split('.')
    if ex in dic:
        dic[ex] += 1
    else:
        dic[ex] = 1

exs = sorted(list(dic.items()))
for ex in exs:
    print(ex[0], ex[1])
