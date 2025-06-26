# 플로이드

import sys
import heapq as hq
from collections import deque
input = sys.stdin.readline
INF = 1e9

n, m, q = map(int, input().split())
cst = [0] + list(map(int, input().split()))
ord = []
arr = [[INF for j in range(n + 1)] for i in range(n + 1)]
res = [[INF for j in range(n + 1)] for i in range(n + 1)]

for i in range(n + 1):
    ord.append((cst[i], i))
ord.sort()

for i in range(m):
    a, b, c = map(int, input().split())
    if (arr[a][b] < c): continue
    tmp = min(cst[a], cst[b])
    arr[a][b] = arr[b][a] = c

for i in range(n + 1):
    arr[i][i] = 0
    res[i][i] = cst[i]

# 플로이드
for k in range(1, n + 1):
    cc = ord[k][0]
    mid = ord[k][1]
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            nc = max(cst[i], cst[j], cc)
            # 최단 거리 계산
            arr[i][j] = min(arr[i][mid] + arr[mid][j], arr[i][j])
            # 최단 (거리 + 방해 시간) 계산
            res[i][j] = min(res[i][j], arr[i][mid] + nc + arr[mid][j])

for i in range(q):
    s, t = map(int, input().split())
    if arr[s][t] == INF:
        print("-1")
    else:
        print(res[s][t])