# bfs
import sys
from collections import deque
input = sys.stdin.readline

def bfs(i, j):
    q = deque()
    q.append((i, j, 0))
    visited[i][j][0] = 1

    while q:
        x, y, b = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue

            if arr[nx][ny] == 1:
                if b < k and visited[nx][ny][b+1] == 0:
                    q.append((nx, ny, b + 1))
                    visited[nx][ny][b+1] = visited[x][y][b] + 1
            elif arr[nx][ny] == 0 and visited[nx][ny][b] == 0:
                q.append((nx, ny, b))
                visited[nx][ny][b] = visited[x][y][b] + 1

n, m, k = map(int, input().split())
arr = [[0 for j in range(m)] for i in range(n)]
visited = [[[0 for _ in range(k + 1)] for j in range(m)] for i in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(n):
    ln = input()
    for j in range(m):
        arr[i][j] = int(ln[j])

bfs(0, 0)

ed = 0
for i in range(k+1):
    if visited[n-1][m-1][i] == 0:
        visited[n-1][m-1][i] = 1e9
    else:
        ed = 1
if ed == 0:
    print("-1")
else:
    print(min(visited[n-1][m-1][i] for i in range(k+1)))