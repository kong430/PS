'''
왼손 엄지는 *, 오른손 엄지는 #에서 시작
1. 상하좌우로 이동 가능, 한 칸은 거리로 1에 해당
2. 1, 4, 7은 왼손 엄지
3. 3, 6, 9는 오른손 엄지
4. 2, 5, 8, 0은 더 가까운 엄지
    거리 같다면, 오른손잡이는 오른엄지 왼손잡이는 왼엄지
각 번호를 누르는 손가락 L or R
'''
def get_hand(num, l, r, hand):
    pos = {1:(0,0), 2:(0,1), 3:(0,2), 4:(1,0), 5:(1,1), 6:(1,2), 7:(2,0), 8:(2,1), 9:(2,2), '*':(3,0), 0:(3, 1), '#':(3,2)}
    left = abs(pos[l][0]-pos[num][0]) + abs(pos[l][1]-pos[num][1])
    right = abs(pos[r][0]-pos[num][0]) + abs(pos[r][1]-pos[num][1])
    
    if left==right:
        return 'L' if hand=='left' else 'R'
    return 'L' if left<right else 'R'
    
def solution(numbers, hand):
    left = {1, 4, 7}
    right = {3, 6, 9}
    cur_left = '*'
    cur_right = '#'
    
    answer = ''
    for n in numbers:
        if n in left:
            answer += 'L'
            cur_left = n
        elif n in right:
            answer += 'R'
            cur_right = n
        else:
            son = get_hand(n, cur_left, cur_right, hand)
            answer += son
            if son=='L':
                cur_left = n
            else:
                cur_right = n
            
    return answer
