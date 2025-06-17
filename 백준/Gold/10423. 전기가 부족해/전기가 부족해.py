# mst
# prim

import sys
import heapq as hq
input = sys.stdin.readline

n, m, k = map(int, input().split())
rt = list(map(int, input().split())) # 발전소 위치
adj = [[] for i in range(n + 1)]
vis = [0 for i in range(n + 1)]
heap = []
sum = 0

for i in range(m):
    a, b, c = map(int, input().split())
    adj[a].append((c, b))
    adj[b].append((c, a))

# root에 연결된 애들 추가
for cur in rt:
    vis[cur] = 1
    for nxt in adj[cur]:
        hq.heappush(heap, nxt)

while heap:
    c, x = hq.heappop(heap)

    if vis[x]: continue

    vis[x] = 1
    sum += c

    for nc, nx in adj[x]:
        if vis[nx]: continue
        hq.heappush(heap, (nc, nx))

print(sum)