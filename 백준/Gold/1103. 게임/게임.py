import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
arr = []

# input
for i in range(n):
    ln = input().strip()
    tmp = []
    for j in ln:
        if j == 'H':
            j = -1
        tmp.append(int(j))
    arr.append(tmp)

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
vis = [[0] * m for j in range(n)]
chk = [[0] * m for j in range(n)]
flag = 0

def dfs(x: int, y: int):
    global flag
    
    if vis[x][y] != 0:
        return vis[x][y]

    vis[x][y] = 1

    # 다음 장소 방문
    for i in range(4):
        # 끝났으면 리턴
        if flag == 1:
            return -1
        
        nx = x + dx[i] * arr[x][y]
        ny = y + dy[i] * arr[x][y]

        # 이동 가능한 좌표인지 확인
        if 0 <= nx < n and 0 <= ny < m and arr[nx][ny] != -1:
            # 이전에 방문한 좌표면 끝내기
            if chk[nx][ny] == 1:
                flag = 1
                return -1

            # 이동할 수 있으면 이동
            chk[nx][ny] = 1
            ret = dfs(nx, ny)
            vis[x][y] = max(vis[x][y], ret + 1)
            chk[nx][ny] = 0

    return vis[x][y]

chk[0][0] = 1
ans = dfs(0, 0)

if flag == 1:
    ans = -1

print(ans)