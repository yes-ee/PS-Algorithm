import sys
input = sys.stdin.readline

n = int(input())

arr = []
adjs = []

for i in range(n):
    arr.append(list(map(int, input().split())))
    for j in range(i + 1, n):
        adjs.append((i, j, arr[i][j]))

adjs.sort(key=lambda x: x[2])

p = [i for i in range(n+1)]
h = [1 for i in range(n+1)]
sum = 0
cnt = 0

def find(x):
    if p[x] == x:
        return x
    return find(p[x])

def merge(u, v):
    u = find(u)
    v = find(v)

    if u == v:
        return False
    
    if h[u] > h[v]:
        u, v = v, u
    p[u] = v
    h[v] = max(h[v], h[u] + 1)

    return True

for cur in adjs:
    a, b, c = cur

    if merge(a, b):
        sum += c
        cnt += 1
        if cnt == n-1:
            break

print(sum)