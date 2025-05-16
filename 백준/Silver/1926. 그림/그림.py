# bfs

import sys
from collections import deque

def bfs(i, j):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    w = 0
    q = deque()
    q.append((i, j))
    arr[i][j] = 0
    w += 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and arr[nx][ny] == 1:
                q.append((nx, ny))
                arr[nx][ny] = 0
                w += 1
    return w

input = sys.stdin.readline
n, m = map(int, input().split())
arr = []
cnt = 0
ans = 0
for i in range(n):
    ln = list(map(int, input().split()))
    arr.append(ln)

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            cnt += 1
            ans = max(ans, bfs(i, j))

print(cnt)
print(ans)