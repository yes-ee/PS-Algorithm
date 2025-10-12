import sys
input = sys.stdin.readline
import bisect

n, m = map(int, input().split())

arr = list(map(int, input().split()))
arr.sort()

for i in range(m):
    cmd = list(map(int, input().split()))
    c = cmd[0]
    if c == 1: # lower bound
        idx = bisect.bisect_left(arr, int(cmd[1]))
        print(n - idx)
    elif c == 2: # upper bound
        idx = bisect.bisect_right(arr, int(cmd[1]))
        print(n - idx)
    else:
        idx_min = bisect.bisect_left(arr, int(cmd[1]))
        idx_max = bisect.bisect_right(arr, int(cmd[2]))
        print(idx_max - idx_min)

# lower bound: k 이상 값이 처음으로 나오는 위치 찾기 -> bisect_left(list, num)
# upper bound: k보다 큰 값의 위치 찾기 -> bisect_right(list, num)