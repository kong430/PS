import math
from itertools import permutations

def is_prime_number(x):
    if x < 2:
        return False
    for i in range(2, int(math.sqrt(x)) + 1):
        if x%i == 0:
            return False
    return True

def solution(numbers):
    nums = list(numbers[i] for i in range(len(numbers)))
    
    answer = []
    for i in range(1, len(nums)+1):
        for case in permutations(nums, i):
            if is_prime_number(int(''.join(case))):
                print(int(''.join(case)))
                answer.append(int(''.join(case)))
    print(set(answer))
    return len(set(answer))
