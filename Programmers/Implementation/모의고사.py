def solution(answers):
    score = [[1, 0], [2, 0], [3, 0]]
    patterns = {1:[1, 2, 3, 4, 5], 2:[2, 1, 2, 3, 2, 4, 2, 5], 3: [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]}
    
    for i in range(len(answers)):
        for j in range(3):
            if answers[i] == patterns[j+1][i%(len(patterns[j+1]))]:
                score[j][1] += 1
                
    score = (sorted(score, key=lambda x:x[1], reverse=True))
    return [p[0] for p in score if p[1] >= score[0][1]]
