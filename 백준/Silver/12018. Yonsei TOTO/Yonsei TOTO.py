# sort

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
subs = [] # 과목별 필요한 마일리지
ans = 0

for i in range(n):
    p, l = map(int, input().split())
    tmp = list(map(int, input().split()))
    if p < l:
        subs.append(1)
        continue
    tmp.sort(reverse=True)
    subs.append(tmp[l-1])

subs.sort()
idx = 0

while idx < n:
    if subs[idx] <= m:
        ans += 1
        m -= subs[idx]
        idx += 1
    else: break

print(ans)