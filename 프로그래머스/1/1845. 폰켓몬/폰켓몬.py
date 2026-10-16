def solution(nums):
    answer = 0
    
    half = len(nums) // 2
    
    pkm = {} # dict 선언
    for num in nums:
        pkm[num] = 1
    
    if half <= len(pkm):
        answer = half
    else:
        answer = len(pkm)
    
    return answer