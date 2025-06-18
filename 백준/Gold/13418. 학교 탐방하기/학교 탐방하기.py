# mst
# 최소 도로 개수 -> v-1
# 최악 경로 : 비용 높은 거 최대로 선택해서 이동
# 최적 경로 : 비용 낮은 거 최대로 선택해서 이동
# mst 두 번

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
edges = []
mn, mx = 0, 0

for i in range(m+1):
    a, b, c = map(int, input().split())
    edges.append((1-c, a, b)) # 오르막길 -> 1 내리막길 -> 0

p = [i for i in range(n + 1)]

# union find
def find(x):
    if p[x] == x: return x
    p[x] = find(p[x])
    return p[x]

def merge(a, b):
    a = find(a)
    b = find(b)

    if a == b: return 0

    p[a] = b
    return 1

# 최단 경로 구하기
edges = sorted(edges)
cnt = 0
sum = 0
for cost, a, b in edges:
    if merge(a, b) == 1: # 다른 그룹
        sum += cost
        cnt += 1
        if cnt == n:
            break

mn = sum * sum

# 최악 경로 구하기
p = [i for i in range(n + 1)]
edges = sorted(edges, reverse=True)
cnt = 0
sum = 0
for cost, a, b in edges:
    if merge(a, b) == 1:
        sum += cost
        cnt += 1
        if cnt == n:
            break

mx = sum * sum

print(mx - mn)