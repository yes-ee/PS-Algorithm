import sys
input=sys.stdin.readline

n, d = map(int, input().split())

dp = [0 for i in range(n + 1)]

for i in range(1, n + 1):
    f = i % 10 # 첫 번째 숫자
    dp[i] = dp[i // 10]
    if f == d:
        dp[i] += 1

print(sum(dp))