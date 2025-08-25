import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = []

aa, bb, cc = 0, 0, 0

for i in range(n):
    idx, a, b, c = map(int, input().split())
    if idx == k:
        aa, bb, cc = a, b, c
    arr.append((a, b, c))

cnt = 1
for a, b, c in arr:
    if a > aa:
        cnt += 1
        continue
    elif a < aa:
        continue
    else:
        if b > bb:
            cnt += 1
            continue
        elif b < bb:
            continue
        else:
            if c > cc:
                cnt += 1
                continue
            else:
                continue

print(cnt)