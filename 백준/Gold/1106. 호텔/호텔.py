import sys
input = sys.stdin.readline
INF = 987654321

c, n = map(int, input().split())
ads = []
dp = [INF for i in range(c+1)]
dp[0] = 0

for i in range(n):
    a, b = map(int, input().split())
    ads.append((a, b))

for i in range(1, c+1):
    for cst, per in ads:
        pre = max(0, i - per)
        dp[i] = min(dp[i], dp[pre] + cst)

print(dp[c])
