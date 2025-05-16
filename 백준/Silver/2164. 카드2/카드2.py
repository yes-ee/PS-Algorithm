import sys
from collections import deque

n = int(sys.stdin.readline().strip())
q = deque()

for i in range(1, n+ 1):
    q.append(i)

flag = 0
while len(q) > 1:
    if flag == 0:
        q.popleft()
    else:
        q.append(q.popleft())
    flag = 1 - flag

print(*q)