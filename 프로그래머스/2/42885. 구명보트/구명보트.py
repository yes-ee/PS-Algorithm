# two pointer

def solution(p, l):
    ans = 0
    s = 0
    e = len(p) -1
    p.sort()
    
    while s <= e:
        sum = p[s] + p[e]
        if sum <= l:
            s += 1
            e -= 1
        else: e -= 1
        ans += 1
    
    return ans
