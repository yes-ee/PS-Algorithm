def solution(temper, t1, t2, a, b, onboard):
    ans = 0
    n = len(onboard) - 1
    INF = 987654321
    
    if temper < t1:
        t1 = -t1 + 40; t2 = -t2 + 40; temper = -temper + 40;
        t1, t2 = t2, t1
    
    dp = [[INF for j in range(51)] for i in range(n + 1)]
    dp[0][temper] = 0
        
    def chk(per, tmp):
        if per == 0:
            return True
        if t1 <= tmp <= t2:
            return True
        return False
        
    for i in range(0, n):
        per = 0
        if onboard[i + 1] == 1: per = 1
        for j in range(51):
            if dp[i][j] == INF: continue
            
            # off
            nxt = j + 1
            if temper == j:
                nxt = j
            if chk(per, nxt):
                dp[i + 1][nxt] = dp[i][j]
            # 유지
            nxt = j
            if chk(per, nxt):
                dp[i + 1][nxt] = min(dp[i][j] + b, dp[i + 1][nxt])
            # 내리기
            if j == 0: continue
            nxt = j - 1
            if chk(per, nxt):
                dp[i + 1][nxt] = min(dp[i][j] + a, dp[i + 1][nxt])

    ans = min(dp[n])
    print(dp[1])
    
    return ans
