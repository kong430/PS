# binary search
n = int(input())
items = list(map(int, input().split()))
m = int(input())
checks = list(map(int, input().split()))

items.sort()

def search(start, end, target):
    if start > end:
        return False
    mid_idx = (start + end) // 2
    if target < items[mid_idx]:
        return search(start, mid_idx-1, target)
    elif target > items[mid_idx]:
        return search(mid_idx+1, end, target)
    else:
        return True

for check in checks:
    if (search(0, len(items)-1, check)) == True:
        print('yes', end=' ')
    else:
        print('no', end=' ')

'''
# counting sort
n = int(input())
items = [0] * 1000001

for i in input().split():
    items[int(i)] = 1
    
m = int(input())
checks = list(map(int, input().split()))

for i in checks:
    if items[i] == 1:
        print('yes', end=' ')
    else:
        print('no', end=' ')
       
# set
n = int(input())
items = set(map(int, input().split()))

m = int(input())
checks = list(map(int, input().split()))

for i in checks:
    if i in items:
        print('yes', end=' ')
    else:
        print('no', end=' ')
'''
