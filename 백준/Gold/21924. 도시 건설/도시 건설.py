# mst

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())
edges = []
p = [i for i in range(n + 1)]
total = 0

for i in range(m):
    a, b, c = map(int, input().split())
    total += c
    edges.append((c, a, b))

edges.sort()

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

sum = 0
cnt = 0

for edge in edges:
    cost, x, y = edge
    if uni(x, y):
        cnt += 1
        sum += cost

    if cnt == n - 1:
        break

pp = find(1)
for i in range(2, n + 1):
    if pp != find(i):
        sum = -1
        break

if sum == -1:
    print("-1")
else:
    print(total - sum)