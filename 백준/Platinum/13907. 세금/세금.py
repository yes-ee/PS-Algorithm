import sys
import heapq
input = sys.stdin.readline
push = heapq.heappush
pop = heapq.heappop

n, m, k = map(int, input().split())
s, d = map(int, input().split())

adjs = [[] for i in range(n+1)]
tax = [0]

for i in range(m):
    a, b, c = map(int, input().split())
    adjs[a].append((c, b))
    adjs[b].append((c, a))

for i in range(k):
    tax.append(int(input()) + tax[-1])

pq = []
dist =[[float('inf') for j in range(n+1)] for i in range(n+1)]
dist[s][0] = 0
push(pq, (0, s, 0)) # cost, x, edge_cnt

while pq:
    cost, x, edge_cnt = pop(pq)

    if edge_cnt == n-1:
        continue

    flag = 0
    for i in range(edge_cnt + 1):
        if dist[x][i] < cost:
            flag = 1
            break

    if flag:
        continue

    for ncost, nx in adjs[x]:
        c = cost + ncost

        if dist[nx][edge_cnt + 1] < c:
            continue

        dist[nx][edge_cnt + 1] = c

        if edge_cnt + 1 < n-1:
            push(pq, (c, nx, edge_cnt + 1))

for i in range(k+1): # i 번째 세금이 올랐을 때
    ans = float('inf')
    for j in range(n): # j개 간선 지남
        ans = min(ans, dist[d][j] + j * tax[i])
    print(ans)