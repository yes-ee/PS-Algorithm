import sys, math
input = sys.stdin.readline

n = int(input())
arr = [list(map(float, input().split())) for i in range(n)]
adj = []

for i in range(n):
    for j in range(i + 1, n):
        a = arr[i]
        b = arr[j]
        res = math.pow(abs(a[0] - b[0]), 2) + math.pow(abs(a[1] - b[1]), 2)
        res = math.sqrt(res)
        adj.append((res, i, j))

adj.sort()

p = [i for i in range(n)]
cnt = 0
sum = 0

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

for cost, u, v in adj:
    if uni(u, v):
        cnt += 1
        sum += cost

        if cnt == n-1:
            break

print("{0:.2f}".format((sum * 100 / 100)))