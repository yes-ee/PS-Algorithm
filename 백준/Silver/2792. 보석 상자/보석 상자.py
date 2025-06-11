import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [int(input()) for i in range(m)]

st = 1
ed = max(arr)
ans = ed

def fn(tar):
    # arr 나눈 개수 더하기
    sum = 0
    for num in arr:
        if num % tar != 0:
            sum += 1
        sum += num // tar

    return sum <= n

# 이분탐색
while 0 < st <= ed:
    mid = (st + ed) // 2

    # mid 결과 <= n
    if fn(mid):
        ans = mid
        ed = mid - 1
    else:
        st = mid + 1

print(ans)