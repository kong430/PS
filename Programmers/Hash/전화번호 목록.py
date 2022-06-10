def solution(phone_book):
    # 시간복잡도 위해 list->set
    nums = set(phone_book)
    
    for num in phone_book:
        for i in range(len(num)):
            if num[:i] in nums:
                return False
    return True
