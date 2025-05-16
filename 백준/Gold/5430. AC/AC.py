import sys
from collections import deque

input = sys.stdin.readline
n = int(input())

for _ in range(n):
    cmd = input().strip()
    dq = deque()
    nn = int(input())
    arr = input().strip()[1:-1].split(',')
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
