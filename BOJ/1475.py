# dictionary
from math import ceil

nums = input()

dic = {}
for num in nums:
    if num == '6' or num == '9':
        k = '69'
    else:
        k = num
    if k in dic:
        dic[k] += 1
    else:
        dic[k] = 1

if '69' in dic:
    dic['69'] = ceil(dic['69']/2)

print(max([x for x in dic.values()]))

'''
# list
from math import ceil

nums = input()
nums_cnt = [0] * 9

for num in nums:
    if num == '9':
        nums_cnt[6] += 1
    else:
        nums_cnt[int(num)] += 1
        
nums_cnt[6] = ceil(nums_cnt[6] / 2)
print(max(nums_cnt))
'''
