'''
한 유저가 어떤 한 유저를 여러 번 신고할 수 있지만, 1회로 처리됨
-> 신고한 유저 id를 key로, 신고한 id를 list로 갖는 dic (value 중복 없도록)
'''
def solution(id_list, report, k):
    report = set(report)
    dic = {id:[] for id in id_list}
    cnt = {id:0 for id in id_list}
        
    for r in report:
        a,b = r.split(' ')
        dic[a].append(b)
        cnt[b] += 1
    
    answer = []
    for user in dic.items():
        receive = 0
        for c in cnt.items():
            if c[1]>=k and c[0] in user[1]:
                receive += 1
        answer.append(receive)
    
    return answer
