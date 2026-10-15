# # 풀이 1
# from functools import cmp_to_key

# def cmp(a, b):
#     if a + b > b + a:
#         return -1
#     else:
#         return 1
#     return 0

# def solution(numbers):
#     answer = ''
    
#     # 숫자 리스트 -> 문자열 리스트로 변환
#     str_numbers = [str(num) for num in numbers]
#     sorted_str_numbers = sorted(str_numbers, key=cmp_to_key(cmp))
    
#     # 리스트 -> 문자열로 합치기
#     answer = ''.join(sorted_str_numbers)

#     if answer[0] == "0":
#         answer = "0"

#     return answer

# 풀이 2
def solution(numbers):
    answer = ''
    
    str_numbers = [str(num) for num in numbers]
    str_numbers.sort(key=lambda x: x*3, reverse=True)
    answer = ''.join(str_numbers)
    # for num in str_numbers:
    #     answer += num
    if answer[0] == '0':
        answer = '0'
    return answer