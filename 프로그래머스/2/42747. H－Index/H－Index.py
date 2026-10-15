def solution(citations):
    answer = 0
    cit = sorted(citations, reverse=True)
    l = len(cit)
    for i in range(l):
        if cit[i] >= i + 1:
            answer = i + 1
    return answer