# 다익스트라

import heapq as hq
import sys
input = sys.stdin.readline
INF = 999999999999

n, m, k = map(int, input().split())
arr = [[] for i in range(n+1)]
dist = [[INF for i in range(k+1)] for i in range(n+1)]

for i in range(m):
    a, b, c = map(int, input().split())
    arr[a].append((c, b))
    arr[b].append((c, a))

h = []
hq.heappush(h, (0, (1, 0)))
dist[1][0] = 0

while h:
    cur = hq.heappop(h)
    c, x, cnt = cur[0], cur[1][0], cur[1][1]

    if dist[x][cnt] < c:
        continue

    for nxt in arr[x]:
        nc, nx = nxt

        if cnt < k and cnt < n:
            cost = c
            if cost < dist[nx][cnt+1]:
                dist[nx][cnt + 1] = cost
                hq.heappush(h, (cost, (nx, cnt + 1)))
        
        cost = c + nc
        if cost < dist[nx][cnt]:
            dist[nx][cnt] = cost
            hq.heappush(h, (cost, (nx, cnt)))


print(min(dist[n]))