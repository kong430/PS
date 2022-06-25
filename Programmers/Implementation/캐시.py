'''
Least Recently Used 적용
cache hit일 경우 +1
cache miss일 경우 +5
'''
from collections import deque

def solution(cacheSize, cities):
    cache = deque(maxlen=cacheSize)
    
    answer = 0
    for city in cities:
        city = city.upper()
        # 캐시에 있을 경우, 순서 변경
        if city in cache:
            answer += 1
            cache.remove(city)
            cache.append(city)
        # 캐시에 없고 캐시가 full일 경우
        elif len(cache)==cacheSize:
            answer += 5
            if cacheSize>0:
                cache.append(city)
        # 캐시에 없고 full이 아닐 경우
        else:
            answer += 5
            cache.append(city)
    
    return answer
