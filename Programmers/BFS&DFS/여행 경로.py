def solution(tickets):
	# key: 시작점, value: 도착지 list (stack)
    routes = dict()
    for t in tickets:
        if t[0] in routes:
            routes[t[0]].append(t[1])
        else:
            routes[t[0]] = [t[1]]
    
    # 알파벳 순서로 빼기 위해 reverse
    for s in routes.keys():
        routes[s].sort(reverse = True)
        
    answer = []
    st = ["ICN"]
    
    while st:
        print(st)
        target = st[-1]
        # target에서 출발할 수 없거나 (마지막 여행지이거나)
        # target에서 출발해서 더 이상 갈 수 있는 공항이 없다면
        if target not in routes or len(routes[target]) == 0:
            answer.append(st.pop())
        else:
            # target에서 출발해서 도착 가능한 공항을 stack에 추가
            st.append(routes[target].pop())
    
    # reverse
    return answer[::-1]
