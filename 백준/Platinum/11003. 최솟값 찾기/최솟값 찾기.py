import sys
from collections import deque

input = sys.stdin.readline

n, l = map(int, input().split())
arr = list(map(int, input().split()))
dq = deque() # 값, 인덱스
ans = []

for i in range(n):
    cur = arr[i]
    # 덱에서 현재값보다 크거나 같은 값 다 pop
    while dq and dq[-1][0] >= cur:
        dq.pop()

    # 현재 값 추가
    dq.append((cur, i))

    # 덱 앞에서부터 인덱스 범위 넘은 거 다 pop
    while dq:
        if dq[0][1] < i - l + 1:
            dq.popleft()
        else:
            break

    # 맨 앞에 값 ans에 추가
    ans.append(dq[0][0])

print(*ans, sep=' ')