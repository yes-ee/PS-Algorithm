import sys
input = sys.stdin.readline

n, c = map(int, input().split())
arr = []

for i in range(n):
    arr.append(int(input()))

arr.sort()

st, ed = 1, arr[-1] - arr[0]
ans = 1

def chk(tar):
    cnt = 1
    idx = 1
    nxt = arr[0] + tar
    while idx < n:
        if arr[idx] >= nxt:
            nxt = arr[idx] + tar
            cnt += 1

        idx += 1
    
    return cnt >= c

while st <= ed:
    mid = (st + ed) // 2
    if chk(mid):
        st = mid + 1
        ans = mid
    else:
        ed = mid - 1

print(ans)