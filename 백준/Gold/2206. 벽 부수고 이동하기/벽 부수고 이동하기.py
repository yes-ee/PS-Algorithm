# bfs

import sys
from collections import deque

def bfs(i, j):
    global visited

    q = deque()
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    q.append((i, j, 0))
    visited[i][j][0] = 1

    while q:
        x, y, b = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:
                if arr[nx][ny] == 1:
                    if b == 0 and visited[nx][ny][1] == 0:
                        q.append((nx, ny, 1))
                        visited[nx][ny][1] = visited[x][y][0] + 1
                elif arr[nx][ny] == 0 and visited[nx][ny][b] == 0:
                    q.append((nx, ny, b))
                    visited[nx][ny][b] = visited[x][y][b] + 1

input = sys.stdin.readline

n, m = map(int, input().split())
arr = [[0 for j in range(m)] for i in range(n)]
visited = [[[0,0] for j in range(m)] for i in range(n)]

for i in range(n):
    ln = input()
    for j in range(m):
        arr[i][j] = int(ln[j])

bfs(0, 0)

if visited[n-1][m-1][0] == 0:
    visited[n - 1][m - 1][0] = 1e9
if visited[n-1][m-1][1] == 0:
    visited[n - 1][m - 1][1] = 1e9

if visited[n-1][m-1][0] == 1e9 and visited[n-1][m-1][1] == 1e9:
    print("-1")
else:
    print(min(visited[n-1][m-1][0], visited[n-1][m-1][1]))

