def solution(nums):
    answer = 0
    half = len(nums) // 2
    pkm = {} # dict 선언
    
    for num in nums:
        pkm[num] = pkm.get(num, 0) + 1
    
    answer = min(half, len(pkm))

    return answer