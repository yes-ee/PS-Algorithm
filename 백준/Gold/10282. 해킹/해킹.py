import sys
input = sys.stdin.readline
import heapq as hq
import math
push = hq.heappush
pop = hq.heappop

t = int(input())
for _ in range(t):
    n, d, c = map(int, input().split())
    adj = [[] for i in range(n+1)]
    dist = [math.inf for i in range(n+1)]

    for i in range(d):
        a, b, s = map(int, input().split())
        adj[b].append((s, a))
    
    heap = []
    dist[c] = 0
    push(heap, (0, c))

    while heap:
        c, x = pop(heap)

        if c > dist[x]:
            continue

        for nc, nx in adj[x]:
            ncost = c + nc
            if ncost < dist[nx]:
                dist[nx] = ncost
                push(heap, (ncost, nx))
    
    cnt = 0
    mx = 0
    for x in dist:
        if x < math.inf:
            cnt += 1
            mx = max(mx, x)
    print(cnt, mx)