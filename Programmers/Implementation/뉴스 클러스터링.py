'''
블라인드 전형 or 코딩 테스트 둘로 분류
자카드 유사도: A, B 두 집합의 교집합 크기 / 두 집합의 합집합 크기 (소수점 허용)
            단, A와 B가 <둘 다> 공집합일 경우 1로 정의
집합: 원소의 중복도 허용함, 자카드 유사도에 대해서도 중복 허용
    교집합에서 해당 원소의 개수: 두 집합에서의 개수 a,b 중 최솟값
    합집합: 최댓값
    
1. 두 글자씩 끊어서 다중집합 원소로 만듦. FRA -> [FR, RA]
2. 영문자가 아닌 문자가 포함되어 있는 원소는 제거

다중집합 원소 간 비교 시, 대문자와 소문자 구분 없음

출력: int(자카드 유사도 * 65536)
'''

# refactor
def solution(str1, str2):
    arr1 = [str1[i:i+2].lower() for i in range(len(str1) - 1) if str1[i:i+2].lower().isalpha()]
    arr2 = [str2[i:i+2].lower() for i in range(len(str2) - 1) if str2[i:i+2].lower().isalpha()]
    if not arr1 and not arr2:
        return 65536

    uu = sum([min(arr1.count(u), arr2.count(u)) for u in list(set(arr1) & set(arr2))])
    nn = sum([max(arr1.count(n), arr2.count(n)) for n in list(set(arr1) | set(arr2))])

    return int(float(uu)/float(nn) * 65536)

'''
# raw
def calc(arr1, arr2):
  hap = {} 

  dic1 = {}
  dic2 = {}
  if len(arr1)==0 and len(arr2)==0:
      return 1
  for a in arr1:
      if a in dic1:
          dic1[a] += 1
      else:
          dic1[a] = 1
  for b in arr2:
      if b in dic2:
          dic2[b] += 1
      else:
          dic2[b] = 1

  # 교집합 개수
  gyo = 0
  for a in dic1.keys():
      if a in dic2.keys():
          gyo += min(dic1[a], dic2[a])

  # 합집합 개수
  hap = 0
  for a in dic1.keys():
      if a in dic2.keys():
          hap += max(dic1[a], dic2[a])
      else:
          hap += dic1[a]
  for b in dic2.keys():
      if not (b in dic1.keys()):
          hap += dic2[b]

  print(hap, gyo)

  return gyo/hap

def make_j(s):
  arr = []
  for i in range(len(s)-1):
      # 문자로만 이루어져 있을 경우
      if s[i].isalpha() and s[i+1].isalpha():
          # 소문자로 통일
          arr.append((s[i]+s[i+1]).lower())
  return arr

def solution(str1, str2):
  arr1 = make_j(str1)
  arr2 = make_j(str2)

  result = calc(arr1, arr2)
  return int(result*65536)
'''
