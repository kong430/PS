'''
- 3<=len(x)<=15
- 소문자, 숫자, '-', '_', '.'
- .는 처음과 끝 불가, 연속 불가
1. s 소문자화
2. 불가능한 문자 모두 제거
3. 마침표 연속된 부분 하나로 치환
4. 마침표 처음과 끝에 있으면 제거
5. s가 빈 문자열이라면 s = 'a'
6. len(s)>=16: s = s[:15]
    s[len(s)-1]=='.'라면 제거
7. len(s)<=2: s길이 3될때까지 끝에 마지막 문자 붙임
'''
def solution(new_id):
    # 1
    s = new_id.lower()
    # 2
    for c in s:
        if c.isalpha() or c.isdigit() or c=='-' or c=='_' or c=='.':
            continue
        else:
            s=s.replace(c, '')
    # 3
    while '..' in s:
        s=s.replace('..', '.')
    # 4 
    if s and s[0]=='.':
        s = s[1:]
    if s and s[-1]=='.':
        s = s[:len(s)-1]
    # 5
    if not s:
        s = 'a'
    # 6
    if len(s)>=16:
        s = s[:15]
    if s[len(s)-1]=='.':
        s = s[:len(s)-1]
    # 7
    while len(s)<3:
        s += s[-1]
    
    return s
