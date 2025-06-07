import sys
input = sys.stdin.readline

n, s = map(int, input().split())
arr = list(map(int, input().split()))

st, ed = 0, 0
ans = 1e9
sum = 0

while ed < n:
    sum += arr[ed]
    # st 줄일 수 있는 곳까지 갱신
    while sum >= s:
        ans = min(ans, ed - st + 1)
        sum -= arr[st]
        st += 1
    ed += 1

if ans == 1e9:
    ans = 0

print(ans)