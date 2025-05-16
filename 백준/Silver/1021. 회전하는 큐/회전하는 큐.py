import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
dq = deque()
arr = list(map(int, sys.stdin.readline().split()))
idx = 0
ans = 0

for i in range(m):
    arr[i] = arr[i] - 1

for i in range(n):
    dq.append(i)

while dq and idx < m:
    cnt = 0
    while True:
        if dq[0] == arr[idx]:
            dq.popleft()
            break
        dq.append(dq.popleft())
        cnt += 1

    cnt = min(cnt, len(dq) + 1 - cnt)
    ans += cnt
    idx += 1

print(ans)