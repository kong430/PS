def solution(s):
    Min = 1e9
    
    if len(s) ==1:
        return 1
    
    for i in range(1, len(s) // 2 + 1):
        # i: 단위 길이
        target_str = s[:i]
        cnt = 1
        new_str = ""
        for j in range(i, len(s), i):
            # j: 문자 시작 idx
            if s[j: j+i] == target_str:
                cnt += 1
            else:
                if cnt != 1:
                    new_str += str(cnt) + target_str
                else:
                    new_str += target_str
                target_str = s[j:j+i]
                cnt = 1
        if cnt != 1:
            new_str += str(cnt) + target_str
        else:
            new_str += target_str
        Min = min(Min, len(new_str))
    return Min
