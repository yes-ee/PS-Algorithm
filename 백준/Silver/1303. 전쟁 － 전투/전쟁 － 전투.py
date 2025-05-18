import sys
from collections import deque

def bfs(i, j, col):
    q = deque()
    q.append((i, j))
    visited[i][j] = 1
    w = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and visited[nx][ny] == 0:
                if arr[nx][ny] == col:
                    q.append((nx, ny))
                    visited[nx][ny] = 1
                    w += 1
    return w


input = sys.stdin.readline
m, n = map(int, input().split())
arr = []
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
visited = [[0 for i in range(m)] for j in range(n)]
a, b = 0, 0

for i in range(n):
    ln = input().strip()
    l = []
    for j in range(m):
        l.append(ln[j])
    arr.append(l)

for i in range(n):
    for j in range(m):
        if visited[i][j] == 1:
            continue
        w = bfs(i, j, arr[i][j])
        if (arr[i][j] == 'W'):
            a += w * w
        else:
            b += w * w
print(a, b)
