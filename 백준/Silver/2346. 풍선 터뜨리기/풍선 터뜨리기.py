import sys
input = sys.stdin.readline
from collections import deque

n = int(input())
arr = list(map(int, input().split()))

ans = []
q = deque()

for i in range(n):
    q.append((arr[i], i + 1))

while len(q) > 1:
    mv, idx = q.popleft()
    ans.append(idx)
    if mv < 0:
        mv *= -1
        for i in range(mv):
            q.appendleft(q[-1])
            q.pop()
    else:
        for i in range(mv-1):
            q.append(q[0])
            q.popleft()

ans.append(q[0][1])

for i in range(n):
    print(ans[i], end=' ')