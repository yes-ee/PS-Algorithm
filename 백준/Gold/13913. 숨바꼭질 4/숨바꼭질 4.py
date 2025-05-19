import sys
from collections import deque
input = sys.stdin.readline

def bfs(x):
    q = deque()
    q.append(x)
    visited[x] = 1

    while q:
        x = q.popleft()
        if x == k:
            return

        for nx in (x-1, x+1, x*2):
            if 0 <= nx <= 200000 and visited[nx] == 0:
                visited[nx] = visited[x] + 1
                path[nx] = x
                q.append(nx)

n, k = map(int, input().split())
visited = [0] * 200001
path = [-1] * 200001

bfs(n)
print(visited[k] - 1)

# path 출력
idx = k
p = []
while True:
    p.append(idx)
    idx = path[idx]
    if idx == -1:
        break

for i in p[::-1]:
    print(i, end=" ")