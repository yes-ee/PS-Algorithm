import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

mn = arr[0][0]
mx = arr[0][0]

for i in range(n):
    for j in range(n):
        if arr[i][j] > mx:
            mx = arr[i][j]
        if arr[i][j] < mn:
            mn = arr[i][j]

s = 0
e = mx - mn

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(st , ed):
    if not (st <= arr[0][0] <= ed and st <= arr[-1][-1] <= ed):
        return -1

    q = deque()
    vis = [[0] * n for _ in range(n)]
    q.append((0, 0))
    vis[0][0] = 1

    while q:
        x, y = q.pop()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < n and vis[nx][ny] == 0:
                if st <= arr[nx][ny] <= ed:
                    if nx == n - 1 and ny == n - 1:
                        return 1

                    vis[nx][ny] = 1
                    q.append((nx, ny))

    return -1

ans = -1

# 이분 탐색으로 구간 범위 설정
while s <= e:
    mid = (s + e) // 2

    # 시작점 설정
    for j in range(mn, mx - mid + 1):
        ret = bfs(j, j + mid)
        if ret == 1:
            ans = mid
            break

    if ans == mid:
        e = mid - 1
    else:
        s = mid + 1

print(ans)