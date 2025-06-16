# topology sort

import sys
from collections import deque

input = sys.stdin.readline
n, m = map(int, input().split())

q = deque()
in_degree = [0] * (n + 1)
arr = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    in_degree[b] += 1

# indegree 0인 점 큐에 삽입
for i in range(1, n + 1):
    if in_degree[i] == 0:
        q.append(i)

# 큐 비어있을 때까지 반복
while q:
    x = q.popleft()
    print(x, end = ' ')

    for num in arr[x]:
        in_degree[num] -= 1
        if in_degree[num] == 0:
            q.append(num)