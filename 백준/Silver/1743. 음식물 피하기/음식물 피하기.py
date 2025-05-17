import sys
from collections import deque

def bfs(x, y):
    q = deque()
    q.append((x, y))
    arr[x][y] = 0
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1,-1]
    w = 1
    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x +dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and arr[nx][ny] == 1:
                q.append((nx, ny))
                arr[nx][ny] = 0
                w += 1
    return w

input = sys.stdin.readline
n, m, k = map(int, input().split())
arr = [[0 for i in range(m)] for j in range(n)]
ans = 0

for i in range(k):
    r, c = map(int, input().split())
    arr[r-1][c-1] = 1

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            ans = max(ans, bfs(i, j))

print(ans)