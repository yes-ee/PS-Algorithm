# dp

import sys
input = sys.stdin.readline
INF = 9999999999
sys.setrecursionlimit(100000)

n = int(input())

arr = []
dp = [[INF for _ in range(n)] for _ in range(n)]
for i in range(n):
    r, c = map(int, input().split())
    arr.append((r, c))
    dp[i][i] = 0

def re(st, ed):
    if dp[st][ed] < INF:
        return dp[st][ed]
    
    for k in range(st, ed):
        sum = re(st, k) + re(k + 1, ed) + arr[st][0] * arr[k][1] * arr[ed][1]
        dp[st][ed] = min(dp[st][ed], sum)
    
    return dp[st][ed]

re(0, n-1)

print(dp[0][n-1])