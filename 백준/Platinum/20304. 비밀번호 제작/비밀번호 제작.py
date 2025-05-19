# bfs

import sys
from collections import deque
input = sys.stdin.readline

def bfs():
    q = deque()
    # 시도한 비밀번호 리스트 삽입
    for num in p:
        q.append(num)
        visited[num] = 1

    while q:
        x = q.popleft()

        # 안전 거리 1인 숫자 방문
        for i in range(0, k):
            nx = x ^ (1 << i)
            if visited[nx] != 0:
                continue
            q.append(nx)
            visited[nx] = visited[x] + 1

n = int(input())
m = int(input())
p = list(map(int, input().split()))
tmp = n
k = 0 # 최대 자릿수
while tmp > 0:
    tmp = tmp >> 1
    k += 1
visited = [0] * (1 << k)
bfs()

# visit 에서 범위 내 최대 거리 구하기
ans = 0
for i in range(0, n+1):
    ans = max(ans, visited[i])
print(ans - 1)