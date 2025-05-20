# bfs
import sys
from collections import deque
input = sys.stdin.readline

def bfs(i, j):
    q = deque()
    q.append((i, j, 0, 1)) # x, y, k, time
    visited[i][j][0] = 1

    while q:
        x, y, b, tm = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue

            # 벽 뚫어야 할 때 -> 낮일 때만 이동 밤일 때는 자리 그대로
            if arr[nx][ny] == 1:
                if b < k and visited[nx][ny][b+1] == 0:
                    if tm % 2 == 1: # 낮
                        q.append((nx, ny, b + 1, tm + 1))
                        visited[nx][ny][b+1] = tm + 1
                    else: # 밤
                        q.append((x, y, b, tm + 1))
            # 벽 뚫을 필요 없을 때 -> 낮 밤 구분 필요 없음
            elif arr[nx][ny] == 0 and visited[nx][ny][b] == 0:
                q.append((nx, ny, b, tm + 1))
                visited[nx][ny][b] = tm + 1

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

