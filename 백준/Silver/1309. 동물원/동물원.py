import sys
input = sys.stdin.readline

n = int(input())
dp = [[1, 1, 1] for i in range(n + 1)]

for i in range(2, n + 1):
    s = sum(dp[i-1])
    dp[i][0] = s % 9901
    dp[i][1] = (s - dp[i-1][1]) % 9901
    dp[i][2] = (s - dp[i-1][2]) % 9901

ans = sum(dp[n]) % 9901
print(ans)