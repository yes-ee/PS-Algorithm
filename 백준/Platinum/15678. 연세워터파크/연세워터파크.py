import sys
from collections import deque
input = sys.stdin.readline

n, d = map(int, input().split())
dp = list(map(int, input().split()))
dq = deque()

# 모노톤 큐 - 감소하는 수열 유지
for i in range(n):
    # 앞에서부터 idx 밖인 거 pop
    while dq:
        if dq[0] < i - d:
            dq.popleft()
        else:
            break
    dp[i] += dp[dq[0]] if dq and dp[dq[0]] > 0 else 0
    
    # 뒤에서부터 새로운 값보다 큰 값 pop
    while dq:
        if dp[dq[-1]] < dp[i]:
            dq.pop()
        else:
            break
    
    # 새로운 값 추가
    dq.append(i)

print(max(dp))