# topology sort

import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
names = list(input().strip().split())
names = sorted(names)

# name -> 숫자로 변환
ndic = dict()
numdic = dict()
idx = 0
for name in names:
    ndic[name] = idx
    idx += 1

# init
deg = [0 for i in range(n + 1)]
adj = [[] for i in range(n + 1)]
ans = [[] for i in range(n + 1)]
rans = []
q = deque()

m = int(input())

# input
for i in range(m):
    a, b = input().split()
    aidx = ndic[a]
    bidx = ndic[b]

    deg[aidx] += 1
    adj[bidx].append(aidx)

# indegree 0인 거 추가
for i in range(n):
    if deg[i] == 0:
        q.append(i)
        rans.append(names[i])
    adj[i] = sorted(adj[i])

rans = sorted(rans)

while q:
    cur = q.popleft()

    for nxt in adj[cur]:
        deg[nxt] -= 1
        if deg[nxt] == 0:
            q.append(nxt)
            ans[cur].append(names[nxt])

# root print
print(len(rans))
print(*rans)

for i in range(n):
    print(names[i], len(ans[i]), *ans[i])