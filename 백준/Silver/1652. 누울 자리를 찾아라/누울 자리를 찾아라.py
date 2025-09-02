import sys
input = sys.stdin.readline

n = int(input())
arr = [input().strip() for i in range(n)]

ca, cb = 0, 0

for i in range(n):
    chk = 0
    for j in range(n-1):
        if arr[i][j] == '.' and arr[i][j+1] == '.':
            chk = 1
        if arr[i][j] == 'X':
            if chk:
                ca += 1
            chk = 0
    if chk:
        ca += 1

for i in range(n):
    chk = 0
    for j in range(n-1):
        if arr[j][i] == '.' and arr[j+1][i] == '.':
            chk = 1
        if arr[j][i] == 'X':
            if chk:
                cb += 1
            chk = 0
    if chk:
        cb += 1

print(ca, cb, sep=' ')