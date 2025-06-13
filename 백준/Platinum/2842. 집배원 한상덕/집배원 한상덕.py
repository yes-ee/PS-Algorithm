import sys
from collections import deque

input = sys.stdin.readline
n = int(input())

arr = [input().strip() for _ in range(n)]
harr =  [list(map(int, input().split())) for _ in range(n)]

# 등장하는 총 숫자 set으로 저장
s = set()
ss = set()
pp = (0, 0)
kcnt = 0
for i in range(n):
    for j in range(n):
        s.add(harr[i][j])
        if arr[i][j] == 'P':
            pp = (i, j)
            ss.add(harr[i][j])
        elif arr[i][j] == 'K':
            ss.add(harr[i][j])
            kcnt += 1


lst = list(s)
lst = sorted(lst)
pklst = list(ss)
ans = lst[-1] - lst[0]

dx = [0, 0, 1, -1, 1, 1, -1, -1]
dy = [1, -1, 0, 0, 1, -1, 1, -1]

def bfs(l, r):
    # 구현
    vis = [[0] * n for _ in range(n)]
    cnt = 0
    dq = deque()
    dq.append(pp)
    vis[pp[0]][pp[1]] = 1

    while dq:
        x, y = dq.popleft()

        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]

            # 범위 내인지 확인
            if not (0 <= nx < n and 0 <= ny < n): continue
            if not (l <= harr[nx][ny] <= r): continue
            if vis[nx][ny] == 1: continue

            if arr[nx][ny] == 'K':
                cnt += 1
            vis[nx][ny] = 1
            dq.append((nx, ny))

            if cnt == kcnt:
                return 1

    return -1

# lst 돌면서 구간 설정
# 해당 구간으로 bfs
l, r = 0, 0
while l <= r < len(lst):
    flag = 0
    # P, K 가 해당 범위에 있는지 확인
    for num in pklst:
        if num < lst[l] or num > lst[r]:
            r += 1
            flag = 1
            break
    if flag:
        continue

    # bfs로 전체 다 방문 가능한지 확인
    ret = bfs(lst[l], lst[r])
    if ret == -1:
        r += 1
    else:
        ans = min(ans, lst[r] - lst[l])
        l += 1

print(ans)