# 다익스트라

import sys
import heapq
input = sys.stdin.readline
INF = 987654321
cnt = 0

while True:
    cnt += 1
    n = int(input())
    if n == 0: break

    arr = []
    for i in range(n):
        tmp = list(map(int, input().split()))
        arr.append(tmp)

    dis = [[INF for i in range(n)] for j in range(n)]
    
    h = []
    h.append((arr[0][0], (0, 0)))
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    while h:
        cur = heapq.heappop(h)
        d = cur[0]
        x, y = cur[1][0], cur[1][1]

        if x == n-1 and y == n-1:
            break

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < n and 0 <= ny < n:
                nd = d + arr[nx][ny]
                if dis[nx][ny] > nd:
                    dis[nx][ny] = nd
                    heapq.heappush(h, (nd, (nx, ny)))

    print(f"Problem {cnt}: {dis[n-1][n-1]}")