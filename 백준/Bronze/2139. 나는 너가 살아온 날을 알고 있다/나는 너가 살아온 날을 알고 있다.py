import sys
input = sys.stdin.readline
arr = [[0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31],
       [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]]

while True:
    d, m, y = map(int, input().split())
    if d == 0:
        break

    idx = 0
    if (y % 4 == 0 and y % 100 != 0) or y % 400 == 0 :
        idx = 1
    cnt = 0
    for i in range(m):
        cnt += arr[idx][i]

    cnt += d
    print(cnt)
