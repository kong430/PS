n-튜플: n개의 요소를 가지 튜플
    중복된 원소 가능
    원소에 순서 정해져 있음, 원소의 순서가 다르면 서로 다른 튜플
집합을 형성 가능한 튜플이 어떤 건지 return
-> 한개짜리가 젤 앞
-> 두개짜리 중 한개짜리가 아닌 원소가 그 뒤
-> ...반복
-> 튜플을 리스트에 저장해 길이별로 sort
'''
def solution(s):
    # {{, }} 제거, },{ 으로 나누기
    data = s[2:-2].split("},{")
    # 길이 별로 오름차순 정렬
    data = sorted(data, key=lambda x: len(x))
    answer = []
    for item in data:
        # 각각의 원소로 분류 후
        item = list(map(int, item.split(",")))
        for value in item:
            # 포함되어 있지 않으면 추가
            if value not in answer:
                answer.append(value)
    return answer
