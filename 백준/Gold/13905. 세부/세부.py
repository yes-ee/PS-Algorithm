# parametric search + dfs

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())
s, e = map(int, input().split())
adj = [[] for i in range(n+1)]

for i in range(m):
    a, b, d = map(int, input().split())
    adj[a].append((b, d))
    adj[b].append((a, d))

st, ed = 1, 1000000
ans = 0
vis = [0 for i in range(n+1)]

def dfs(x, tar):
    global vis

    vis[x] = 1

    if x == e:
        return True
    
    for nxt in adj[x]:
        nx, dis = nxt[0], nxt[1]
        if vis[nx] or dis < tar:
            continue

        if dfs(nx, tar):
            return True
    
    return False
    
# st -> ed 이동 가능한지 확인
def chk(tar):
    return dfs(s, tar)

while st <= ed:
    vis = [0 for i in range(n+1)]
    mid = (st + ed) // 2
    
    if chk(mid):
        ans = mid
        st = mid + 1
    else:
        ed = mid - 1

print(ans)