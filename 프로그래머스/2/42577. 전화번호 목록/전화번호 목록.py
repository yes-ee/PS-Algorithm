def check(a, b):
    # a, b는 문자열
    # 다르면 0, 접두사면 1
    if len(a) > len(b):
        return 0
    for i in range(len(a)):
        if a[i] != b[i]:
            return 0
    return 1

def solution(phone_book):
    answer = True
    
    # sort
    sorted_book = sorted(phone_book)
    
    # 전체 순회
    n = len(sorted_book)
    for i in range(n-1):
        res = check(sorted_book[i], sorted_book[i+1])
        if res == 1:
            return False
            
    return answer