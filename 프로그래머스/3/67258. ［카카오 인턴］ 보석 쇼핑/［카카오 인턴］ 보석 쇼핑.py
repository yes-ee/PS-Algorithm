# two pointer

def solution(gems):
    length = len(gems)
    type_cnt = len(set(gems))
    ans = [1, length]
    ans_len = length
    
    st, ed = 0, 0
    dic = {gems[0]: 1}
    
    while st <= ed and ed < length:
        if len(dic) < type_cnt:
            ed += 1
            if ed == length:
                break
            dic[gems[ed]] = dic.get(gems[ed], 0) + 1
        else:
            if ed - st + 1 < ans_len:
                ans = [st + 1, ed + 1]
                ans_len = ed - st + 1
            
            dic[gems[st]] -= 1
            if dic[gems[st]] == 0:
                dic.pop(gems[st])
            
            st += 1
    return ans