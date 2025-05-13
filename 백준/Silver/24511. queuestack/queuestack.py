import sys

n = sys.stdin.readline()
tp = sys.stdin.readline().split()
arr = sys.stdin.readline().split()

m = sys.stdin.readline()
cmd = sys.stdin.readline().split()

lst = []

# input number append
for i in range(int(m)-1, -1, -1):
    lst.append(cmd[i])

for i in range(int(n)):
    if tp[i] == '0':
        lst.append(arr[i])

idx = 0
for i in range(int(n)):
    if tp[i] == '1':
        continue
    arr[i] = lst[idx]
    idx += 1

for i in range(len(lst) - 1, idx-1, -1):
    print(lst[i], end=' ')
