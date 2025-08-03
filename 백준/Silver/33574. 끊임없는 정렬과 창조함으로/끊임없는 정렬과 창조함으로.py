import sys
input = sys.stdin.readline

arr = []
q = int(input())
for i in range(q):
    cmds = list(map(int, input().split()))
    if cmds[0] == 1:
        if cmds[1] == 1:
            arr.sort()
        else:
            arr.sort(reverse=True)
    else:
        x, t = cmds[1], cmds[2]
        if x == 0:
            arr.insert(0, t)
        elif x == len(arr):
            arr.append(t)
        else:
            arr.insert(x, t)

print(len(arr))
if arr:
    for num in arr:
        print(num, end=' ')