def solution(msg):
    dic = {chr(i):i-64 for i in range(65, 91)}
    answer = []
    
    while True:
        longest = ['', -1] #[w, idx]
        last_idx = 0
        # 현재 입력과 일치하는 가장 긴 문자열 w와 그 idx 찾기
        for i in range(1, len(msg)+1):
            for d in dic.items():
                if msg[:i]==d[0]:
                    longest = d
        # 해당 idx 출력, 입력에서 w 제거
        answer.append(longest[1])
        msg = msg[last_idx+len(longest[0]):]
        
        # 입력에서 처리되지 않은 다음 글자 남아 있을 경우
        if msg:
            dic[longest[0]+msg[0]] = len(dic) + 1
        else:
            break

    return answer
