import sys
import heapq as hq
from collections import deque
input = sys.stdin.readline
INF = 1e9

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0: break # 종료 조건

    s, e = map(int, input().split())
    adj = [[] for i in range(n)]
    d = [INF for i in range(n)]
    p = [[] for i in range(n)] # 이전 경로 리스트
    vis = [0 for i in range(n)] # 경로 복원 시 방문 여부 저장
    heap = []
    ss = set()

    for i in range(m):
        u, v, c = map(int, input().split())
        adj[u].append((c, v))

    # s에서 모든 정점까지 최단 경로 구하기 -> 다익스트라
    d[s] = 0
    hq.heappush(heap, (d[s], s))
    
    while heap:
        cc, cx = hq.heappop(heap)

        if cc != d[cx]: continue
        for nc, nx in adj[cx]:
            if d[nx] < cc + nc: continue # 최단 거리 아님
            if d[nx] == (cc + nc):
                p[nx].append(cx)
                continue
            p[nx] = []
            p[nx].append(cx)
            d[nx] = cc + nc
            hq.heappush(heap, (d[nx], nx))
    
    # 경로 복원
    # dfs
    st = []
    st.append(e)
    vis[e] = 1
    while st:
        cur = st.pop()

        for nxt in p[cur]:
            ss.add((nxt, cur))
            if vis[nxt]: continue
            vis[nxt] = 1
            st.append(nxt)
    
    # 방문 가능한 경로로 최단 거리 구하기 -> 다익스트라
    dd = [INF for i in range(n)]
    # s에서 모든 정점까지 최단 경로 구하기 -> 다익스트라
    dd[s] = 0
    hq.heappush(heap, (dd[s], s))
    
    while heap:
        cc, cx = hq.heappop(heap)

        if cc != dd[cx]: continue
        for nc, nx in adj[cx]:
            if (cx, nx) in ss: continue
            if dd[nx] <= cc + nc: continue # 최단 거리 아님
            dd[nx] = cc + nc
            hq.heappush(heap, (dd[nx], nx))
    
    if dd[e] == INF:
        dd[e] = -1
    print(dd[e])