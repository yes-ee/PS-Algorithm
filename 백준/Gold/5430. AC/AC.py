import sys
from collections import deque

n = int(sys.stdin.readline())

for _ in range(n):
    cmd = sys.stdin.readline().strip()
    dq = deque()
    nn = int(sys.stdin.readline())
    arr = sys.stdin.readline().strip().lstrip('[').rstrip(']').split(',')
    if arr[0] != '':
        for num in arr:
            dq.append(int(num))

    end = 0
    dir = 0 # 0 left pop 1 right pop
    for i in range(len(cmd)):
        if cmd[i] == 'R':
            dir = 1 - dir
        else:
            if not dq:
                print("error")
                end = 1
                break
            if dir == 0:
                dq.popleft()
            else:
                dq.pop()
    if end == 1:
        continue
    if dir == 1:
        dq.reverse()

    print("[", end="")
    while len(dq) > 1:
        print(dq.popleft(), end=",")
    if dq:
        print(dq.popleft(), end="")
    print("]")
