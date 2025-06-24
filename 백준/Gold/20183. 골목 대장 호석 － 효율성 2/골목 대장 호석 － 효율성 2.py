# 다익스트라, 이분탐색

import sys
input = sys.stdin.readline
import heapq as hq
INF = 1e20

n, m, a, b, c = map(int, input().split())
adj = [[] for i in range(n + 1)]
mx = 0

for i in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((w, v))
    adj[v].append((w, u))
    mx = max(mx, w)

# 이분탐색
st = 0
ed = mx
ans = -1

# 다익스트라
def fn(tar):
    heap = []
    d = [INF for i in range(n + 1)]
    hq.heappush(heap, (0, a))
    d[a] = 0

    while heap:
        cc, cx = hq.heappop(heap)

        if d[cx] != cc: continue
        for nc, nx in adj[cx]:
            if nc > tar: continue # 기준 최대금액 초과
            if d[nx] <= (cc + nc): continue
            if (cc + nc) > c: continue # 가진 돈 초과
            d[nx] = cc + nc
            hq.heappush(heap, (d[nx], nx))
    
    # 도착점 d값이 INF면 false 리턴
    if d[b] == INF: return False
    return True

while st <= ed:
    mid = (st + ed) // 2
    if fn(mid):
        ans = mid
        ed = mid - 1
    else:
        st = mid + 1

print(ans)