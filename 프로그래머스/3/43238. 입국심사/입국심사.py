

def solution(n, times):
    length = len(times) # 심사대 개수
    
    st, ed = 1, min(times) * n
    ans = ed
    
    def chk(tar):
        cnt = 0
        for time in times:
            cnt += tar // time
        
        if cnt >= n:
            return True
        else:
            return False

    while st <= ed:
        mid = (st + ed) // 2
        
        if chk(mid):
            ans = mid
            ed = mid - 1
        else:
            st = mid + 1
    
    return ans
