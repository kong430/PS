def solution(brown, yellow):
    # i, j는 전체의 가로, 세로
    for i in range(3, 2500):
        for j in range(3, i+1):
            if (i-2)*(j-2) == yellow and i*j-(i-2)*(j-2) == brown:
                return [i,j]
