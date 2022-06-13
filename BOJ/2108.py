n = int(input())
nums = [int(input()) for _ in range(n)]

def first(nums):
    total = sum(nums)
    cnt = len(nums)
    print(round(total/cnt))    
    
def second(nums):
    nums = sorted(nums)
    print(nums[len(nums)//2])
    
def third(nums):
    dic = {}
    for num in nums:
        if num in dic:
            dic[num] += 1
        else:
            dic[num] = 1
    arr = sorted(dic.items(), key=lambda x:(x[1], x[0]), reverse=True)
    if len(arr)>1 and arr[0][1] == arr[1][1]:
        mosts = [item[0] for item in arr if item[1] == arr[0][1]]
        mosts = sorted(mosts)
        print(mosts[1])
    else:
        print(arr[0][0])
    
def fourth(nums):
    nums = sorted(nums)
    print(nums[len(nums)-1] - nums[0])
    
first(nums[:])
second(nums[:])
third(nums[:])
fourth(nums[:])
