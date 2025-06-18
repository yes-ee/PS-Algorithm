# 그리디
# 양수/음수 중 제일 먼 거는 한 번만 이동
# 나머지는 두 번 이동

import sys
import heapq as hq
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))

arr = sorted(arr)
idx = n

for i in range(n):
    if arr[i] > 0:
        idx = i
        break

narr = arr[:idx]
parr = arr[idx:]
parr.reverse()

ns, ne = 0, len(narr)
ps, pe = 0, len(parr)

flag = 0
if ne == 0:
    ps += m
    flag = 1
elif pe == 0:
    ns += m
elif abs(narr[0]) > parr[0]:
    ns += m
else:
    ps += m
    flag = 1

sum = 0

for i in range(ns, ne, m):
    sum += abs(narr[i])

for i in range(ps, pe, m):
    sum += abs(parr[i])

sum *= 2

if flag == 0:
    sum += abs(narr[0])
else:
    sum += parr[0]

print(sum)