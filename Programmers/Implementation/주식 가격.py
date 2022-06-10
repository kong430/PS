def solution(prices):
    answer = [i for i in range(len(prices)-1, -1, -1)]
    st = []
    
    for i, price in enumerate(prices):
        while st:
            if st[-1][1] > price:
                answer[st[-1][0]] = i - st[-1][0]
                st.pop()
            else:
                break
        st.append((i, price))
        
    return answer
