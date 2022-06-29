from bisect import bisect_left, bisect_right

def cal_cnt(arr, s):
    left = bisect_left(arr, s.replace('?','a'))
    right = bisect_right(arr, s.replace('?','z'))
    return right-left

def solution(words, queries):
    reversed_words = [[] for _ in range(10001)]
    ori_words = [[] for _ in range(10001)]
    
    for w in words:
        ori_words[len(w)].append(w)
        reversed_words[len(w)].append(w[::-1])
    for i in range(10001):
        ori_words[i].sort()
        reversed_words[i].sort()
    
    answer = []
    for q in queries:
        if q[0]=='?':
            answer.append(cal_cnt(reversed_words[len(q)], q[::-1]))
        else:
            answer.append(cal_cnt(ori_words[len(q)], q))
        
    return answer
