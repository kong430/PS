import sys
from collections import deque

n,k = map(int,input().split())
belt = deque(map(int,sys.stdin.readline().split()))
ans = 1

# 로봇 현재 위치
robot = deque([0]*(n*2))

while(True):
    #1
    belt.rotate(1)
    robot.rotate(1)
    robot[n-1]=0 # 내리는 곳에 로봇 있다면 삭제

    #2
    for i in range(n-2,-1,-1): # 가장 먼저 올라간 로봇부터
        if(robot[i]!=0 and robot[i+1]==0 and belt[i+1]>=1):
            belt[i+1]-=1
            robot[i+1]=robot[i]
            robot[i]=0
    robot[n-1]=0

    #3
    if(robot[0]==0 and belt[0]>0):
        belt[0]-=1
        robot[0]=1

    #4
    if belt.count(0)>=k:
        print(ans)
        break

    ans+=1
