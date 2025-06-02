import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
lst = []
ans = 0
cur = 0

for i in range(n):
    s, e = map(int, input().split())
    lst.append((s, 1))
    lst.append((e, -1))

slst = sorted(lst, key=lambda x: (x[0], x[1]))
dq = deque(slst)

while dq:
    tm, tp = dq.popleft()
    cur += tp
    ans = max(ans, cur)

print(ans)