# dfs + 사이클 판단

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())
arr = []
vis = [[0 for j in range(m)] for i in range(n)]

for i in range(n):
    ln = input().strip()
    tmp = []
    for c in ln:
        tmp.append(ord(c) - ord('A'))
    arr.append(tmp)

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def dfs(x, y, px, py):
    vis[x][y] = 1

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < n and 0 <= ny < m:
            if arr[x][y] != arr[nx][ny]: continue
            if px == nx and py == ny: continue
            if vis[nx][ny]: # 사이클
                print("Yes")
                exit(0)
            dfs(nx, ny, x, y)

for i in range(n):
    for j in range(m):
        if vis[i][j]: continue
        dfs(i, j, -1, -1)

print("No")