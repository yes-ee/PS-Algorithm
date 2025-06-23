# 다익스트라

import sys
input = sys.stdin.readline
import heapq as hq
INF = 1e9

v, e = map(int, input().split())
k = int(input())

# 간선 저장
adj = [[] for i in range(v + 1)]
for i in range(e):
    a, b, c = map(int, input().split())
    adj[a].append((c, b))

heap = list()
d = [INF for i in range(v + 1)]

# 시작점 추가
hq.heappush(heap, (0, k))
d[k] = 0

while heap:
    c, x = hq.heappop(heap)

    if c != d[x]: continue

    for nc, nx in adj[x]:
        if d[nx] <= c + nc: continue
        d[nx] = c + nc
        hq.heappush(heap, (d[nx], nx))

for i in range(1, v + 1):
    if d[i] == INF:
        print("INF")
    else:
        print(d[i])