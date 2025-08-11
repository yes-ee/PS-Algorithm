# 다익스트라

import heapq as hq
import sys
input = sys.stdin.readline
INF = 999999999999

n, m = map(int, input().split())
arr = [[] for _ in range(n+1)]

for i in range(m):
    a, b, d = map(int, input().split())
    arr[a].append((d, b))
    arr[b].append((d, a))

dist_fox = [INF for i in range(n + 1)]
dist_wolf = [[INF, INF] for i in range(n + 1)]

def get_fox_dist():
    global dist_fox

    h = []
    hq.heappush(h, (0, 1))
    dist_fox[1] = 0

    while h:
        c, x = hq.heappop(h)

        if dist_fox[x] < c:
            continue

        for nxt in arr[x]:
            nc, nx = nxt
            cost = dist_fox[x] + (nc << 1)

            if cost >= dist_fox[nx]:
                continue

            dist_fox[nx] = cost
            hq.heappush(h, (cost, nx))

def get_wolf_dist():
    global dist_wolf

    h = []
    hq.heappush(h, (0, 1, 1)) # cost, v, speed time 0->fast, 1->slow
    dist_wolf[1][1] = 0

    while h:
        c, x, t = hq.heappop(h)

        if dist_wolf[x][t] < c:
            continue

        for nxt in arr[x]:
            nc, nx = nxt
            nt = 1 - t
            if nt == 1:
                nc <<= 2
            cost = dist_wolf[x][t] + nc

            if cost >= dist_wolf[nx][nt]:
                continue

            dist_wolf[nx][nt] = cost
            hq.heappush(h, (cost, nx, nt))

get_fox_dist()
get_wolf_dist()

ans = 0
for i in range(1, n+1):
    if dist_fox[i] < min(dist_wolf[i]):
        ans += 1

print(ans)