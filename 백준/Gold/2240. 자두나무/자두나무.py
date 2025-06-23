# dp

import sys
input = sys.stdin.readline

t, w = map(int, input().split())
arr = [-1]

for i in range(t):
    num = int(input())
    arr.append(num - 1)

dp = [[[0, 0] for j in range(w + 1)] for i in range(t + 1)]

for i in range(1, t + 1):
    dp[i][0][0] = dp[i-1][0][0]
    if arr[i] == 0:
        dp[i][0][0] += 1
    for j in range(1, w + 1):
        for k in range(2):
            dp[i][j][k] = max(dp[i-1][j-1][1-k], dp[i-1][j][k])
            if arr[i] == k:
                dp[i][j][k] += 1

ans = 0
for j in range(w + 1):
    for k in range(2):
        ans = max(ans, dp[t][j][k])

print(ans)