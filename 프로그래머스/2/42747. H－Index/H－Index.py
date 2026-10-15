def solution(citations):
    answer = 0
    cit = sorted(citations, reverse=True)
    for i in range(len(cit)):
        if cit[i] >= i + 1:
            answer = i + 1
    return answer