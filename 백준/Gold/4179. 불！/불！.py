# 시작점이 여러 개인 bfs

import sys
from collections import deque
input = sys.stdin.readline

r, c = map(int, input().split())
arr = []
vis = [[0 for j in range(c)] for i in range(r)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for i in range(r):
    ln = input().strip()
    tmp = []
    for j in range(c):
        tmp.append(ln[j])
    arr.append(tmp)

q = deque() # x, y, type(1, 2)
# 불 위치 추가
for i in range(r):
    for j in range(c):
        if arr[i][j] == 'F':
            q.append((i, j, 2))

# 지훈이 위치 추가
for i in range(r):
    for j in range(c):
        if arr[i][j] == 'J':
            q.append((i, j, 1))
            vis[i][j] = 1

end = 0
while q and end == 0:
    x, y, t = q.popleft()
    # 불 위치 갱신
    if t == 2:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= r or ny < 0 or ny >= c:
                continue
            if arr[nx][ny] == '#' or arr[nx][ny] == 'F':
                continue

            q.append((nx, ny, t))
            arr[nx][ny] = 'F'
    # 지훈이 위치 갱신
    elif t == 1:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= r or ny < 0 or ny >= c:
                print(vis[x][y])
                end = 1
                break
            if arr[nx][ny] == '#' or arr[nx][ny] == 'F' or vis[nx][ny] != 0:
                continue

            q.append((nx, ny, t))
            vis[nx][ny] = vis[x][y] + 1

if end == 0:
    print("IMPOSSIBLE")