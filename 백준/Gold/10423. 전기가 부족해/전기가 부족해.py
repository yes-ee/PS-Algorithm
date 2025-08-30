# mst
# prim

import sys
import heapq as h
push = h.heappush
pop = h.heappop
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n, m, k = map(int, input().split())
rt = list(map(int, input().split())) # 발전소 위치
pq = []

def prim():
    sum = 0
    vis = [0 for i in range(n + 1)]

    adj = [[] for i in range(n + 1)]

    for i in range(m):
        a, b, c = map(int, input().split())
        adj[a].append((c, b))
        adj[b].append((c, a))

    # root에 연결된 애들 추가
    for cur in rt:
        vis[cur] = 1
        for nxt in adj[cur]:
            push(pq, nxt)

    while pq:
        c, x = pop(pq)

        if vis[x]: continue

        vis[x] = 1
        sum += c

        for nc, nx in adj[x]:
            if vis[nx]: continue
            push(pq, (nc, nx))

    print(sum)

def kruskal():
    sum = 0
    p = [i for i in range(n+1)]
    edges = []

    for i in range(m):
        a, b, c = map(int, input().split())
        edges.append((c, a, b))

    edges.sort()

    # 발전소를 그룹 0번으로 묶음
    for x in rt:
        p[x] = 0

    def find(u):
        if p[u] == u:
            return u
        p[u] = find(p[u])
        return p[u]

    def uni(u, v):
        u = find(u)
        v = find(v)

        if u == v:
            return False
        p[u] = v
        return True

    cnt = k

    for edge in edges:
        cost, x, y = edge

        if uni(x, y):
            cnt += 1
            sum += cost

            if cnt == n:
                break

    print(sum)

kruskal()