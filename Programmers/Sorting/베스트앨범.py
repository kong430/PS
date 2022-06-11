def solution(genres, plays):
    answer = []
    dic = {}
    for i in range(len(genres)):
        if genres[i] in dic.keys():
            dic[genres[i]][0] += plays[i]
            dic[genres[i]][1].append((i, plays[i]))
        else:
            dic[genres[i]] = [plays[i], [(i, plays[i])]]
            
    dic = dict(sorted(dic.items(), key=lambda x:(x[1][0]), reverse=True))
    
    values = list(dic.values())    
    for value in values:
        songs = value[1]
        songs.sort(key=lambda x:x[1], reverse=True)
        for i in range(min(len(songs), 2)):
            answer.append(songs[i][0])
        
    return (answer)
