'''
영어 대소문자, 숫자, ' ', '.', '-'
영문자로 시작, 숫자 한 개 이상 포함
head: 문자로만, 최소 한 글자 이상
number: 한글자~다섯글자 숫자, !앞에 0이 올 수 있음!
tail: number 뒤에 오는 나머지 부분 (숫자, 영어, 특수문자, 빈문자열 등)
1. head 기준 사전순 정렬, 대소문자 비교 X
2. 같을 경우 number 숫자 기준으로 정렬, 숫자 앞의 0은 무시
3. 또 같을 경우, 입력 순서 유지 (정렬 후 순서 뒤바뀌면 안 됨)
'''

def solution(files):
    tmp = [] # (head(대문자), number(int), idx, 파일명)
    for index, file in enumerate(files):
        idx = 0
        head = ''
        number = ''
        for i in range(idx, len(file)):
            if not file[i].isdigit():
                head += file[i]
                idx += 1
            else:
                break
        for i in range(idx, len(file)):
            if file[i].isdigit():
                number += file[i]
            else:
                break
        tmp.append((head.upper(), int(number), index, file))

    tmp.sort()
    return [tmp[i][3] for i in range(len(tmp))]
