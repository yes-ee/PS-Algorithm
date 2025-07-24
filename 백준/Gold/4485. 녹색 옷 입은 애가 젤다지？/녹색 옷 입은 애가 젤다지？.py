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
    heapq.heapify(h)
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    while h:
        cur = heapq.heappop(h)
        d = cur[0]
        x, y = cur[1][0], cur[1][1]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < n:
                if dis[nx][ny] > d + arr[nx][ny]:
                    dis[nx][ny] = d + arr[nx][ny]
                    heapq.heappush(h, (dis[nx][ny], (nx, ny)))

    print("Problem ", cnt, ": ", dis[n-1][n-1], sep='')                