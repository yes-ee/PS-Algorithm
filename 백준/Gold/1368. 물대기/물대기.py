# mst

import sys
import heapq as h
push = h.heappush
pop = h.heappop
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
pq = []
for i in range(n):
    cost = int(input())
    push(pq, (cost, i, i))

for i in range(n):
    tmp = list(map(int, input().split()))
    for j in range(n):
        if i == j:
            continue
        push(pq, (tmp[j], i, j))

p = [i for i in range(n)]
rt = [-1 for i in range(n)]

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
    if rt[v] == -1:
        rt[v] = rt[u]
    
    return True

cnt_node = 0
cnt_edge = 0
sum = 0

while pq:
    cost, x, y = pop(pq)

    if x == y:
        if rt[find(x)] != -1:
            continue
        rt[find(x)] = 1
        cnt_node += 1
        sum += cost
    else:
        if cnt_edge == n-1:
            continue

        if rt[find(x)] != -1 and rt[find(y)] != -1:
            continue

        if uni(x, y):
            cnt_edge += 1
            sum += cost
        else:
            continue

    if cnt_edge + cnt_node == n:
        break

print(sum)
