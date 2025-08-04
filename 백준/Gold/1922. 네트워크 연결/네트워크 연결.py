import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
adjs = []
sum = 0
cnt = 0

for i in range(m):
    a, b, c = map(int, input().split())
    if a == b: continue

    adjs.append((a, b, c))

p = [i for i in range(n+1)]
h = [0 for i in range(n+1)]

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

adjs.sort(key=lambda x : x[2])

for cur in adjs:
    a, b, c = cur
    
    if merge(a, b):
        sum += c
        cnt += 1
        if cnt == n-1:
            break

print(sum)