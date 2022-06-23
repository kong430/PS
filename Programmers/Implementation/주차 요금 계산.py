'''
요금표, 차량별 입차/출차 시간 -> 차량별 주차 요금
입차 후 출차 내역이 업삳면, 23:59에 출차된 것으로 간주
00:00~23:59 까지의 누적 주차 시간 계산, 일괄 정산
    x<=기본시간 => 기본 요금
    x>기본시간 => 기본 요금 + 초과시간/단위시간 (올림) *단위요금
fees = (기본 시간, 기본 요금, 단위 시간(분), 단위 요금)
'''
import math

def cal_fee(bt, bf, ut, uf, minutes):
    if minutes<=bt:
        return bf
    return bf+math.ceil((minutes-bt)/ut)*uf

def cal_time(s, e):
    s_hour, s_minute = s.split(':')
    e_hour, e_minute = e.split(':')
    return int(e_hour)*60+int(e_minute) - (int(s_hour)*60+int(s_minute))

def solution(fees, records):
    dic = {}
    total_minutes = {}
    fee = {}
    base_time, base_fee, unit_time, unit_fee = fees
    
    for r in records:
        time, car, ntype = r.split(' ')
        if not car in fee:
            fee[car] = 0
        if not car in total_minutes:
            total_minutes[car] = 0
        # 입차 시 dic에 시간 추가
        if ntype=="IN":
            dic[car] = time
        # 출차 시 소요 시간 계산 후 dic에서 제거
        else:
            minutes = cal_time(dic[car], time)
            total_minutes[car] += minutes
            del dic[car]
    
    # 들어왔는데 안 나간 차가 있을 경우
    for d in dic.items():
        minutes = cal_time(d[1], "23:59")
        total_minutes[d[0]] += minutes
    
    # 요금 정산
    for c in total_minutes.items():
        fee[c[0]] = cal_fee(base_time, base_fee, unit_time, unit_fee, c[1])
    
    fee = dict(sorted(fee.items()))
    return list(fee.values())
