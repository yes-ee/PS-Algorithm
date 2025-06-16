# mst
# kruskal

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

v, e = map(int, input().split())
graph = []

for i in range(e):
    a, b, c = map(int, input().split())
    graph.append([c, a, b]) # 튜플로 추가

graph = sorted(graph) # 오름차순 정렬

ans = 0

# union find
p = [i for i in range(v + 1)]

def find(x):
    if p[x] == x:
        return x

    p[x] = find(p[x])
    return p[x]

def uni(a, b):
    a = find(a)
    b = find(b)

    if a == b: return 0

    p[a] = b

    return 1

for cost, a, b in graph:
    if uni(a, b) == 1:
        ans += cost

print(ans)
