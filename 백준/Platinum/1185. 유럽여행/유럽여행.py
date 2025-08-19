# mst
import math
import sys
import heapq
input = sys.stdin.readline
push = heapq.heappush
pop = heapq.heappop

n, m = map(int, input().split())
c = [math.inf] + [int(input()) for _ in range(n)]

pq = []
for i in range(m):
    s, e, l = map(int, input().split())
    l = l * 2 + c[s] + c[e]
    push(pq, (l, s, e))

p = [i for i in range(n+1)]

def find(u):
    if p[u] == u:
        return u
    p[u] = find(p[u])
    return p[u]

def merge(u, v):
    u = find(u)
    v = find(v)

    if u == v:
        return False

    p[u] = v
    return True

cnt = 0
sum = 0
while pq:
    l, s, e = pop(pq)

    if merge(s, e):
        cnt += 1
        sum += l

        if cnt == n-1:
            break

sum += min(c)
print(sum)