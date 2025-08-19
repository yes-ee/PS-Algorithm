# mst

import sys
import heapq
input = sys.stdin.readline
push = heapq.heappush
pop = heapq.heappop

n, m = map(int, input().split())
c = [0] + [int(input()) for _ in range(n)]

pq = []
for i in range(m):
    s, e, l = map(int, input().split())
    l = l * 2 + c[s] + c[e]
    push(pq, (l, s, e))

p = [i for i in range(n+1)]

def find(u):
    if p[u] == u:
        return u
    return find(p[u])

def merge(u, v):
    u = find(u)
    v = find(v)

    if u == v:
        return False

    p[u] = v
    return True

cnt = 0
sum = 0
min_node = 999999
while pq:
    l, s, e = pop(pq)
    mm = min(c[s], c[e])

    if merge(s, e):
        cnt += 1
        sum += l
        if mm < min_node:
            min_node = mm

        if cnt == n-1:
            break

sum += min_node
print(sum)