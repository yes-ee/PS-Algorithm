# 다익스트라

import sys
input = sys.stdin.readline
import heapq as hq
INF = 9876543210

n, m, k = map(int, input().split())

# 간선 추가
adj = [[] for i in range(n+1)]
for i in range(m):
    a, b, c = map(int, input().split())
    adj[a].append((c, b))

h = []
dis = [[INF for j in range(k)] for i in range(n+1)]
dis[1][0] = 0
hq.heappush(h, (0, 1))

def check_cost(c, x):
    if c >= dis[x][-1]:
        return True
    
    return False

while h:
    c, x = hq.heappop(h)

    for nc, nx in adj[x]:
        if check_cost(nc + c, nx):
            continue

        dis[nx][-1] = nc + c
        dis[nx].sort()
        hq.heappush(h, (nc + c, nx))

for x in range(1, n+1):
    if dis[x][k-1] >= INF:
        print("-1")
    else:
        print(dis[x][k-1])
