import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))

arr = sorted(arr)

st, ed = 0, n-1
ans = 0
while st < ed:
    sum = arr[st] + arr[ed]
    if sum >= m:
        ans += 1
        st += 1
        ed -= 1
    else:
        st += 1

print(ans)