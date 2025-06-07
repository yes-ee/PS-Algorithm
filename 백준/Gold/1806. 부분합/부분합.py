import sys
input = sys.stdin.readline

n, s = map(int, input().split())
arr = list(map(int, input().split()))

st, ed = 0, 0
ans = 1e9
sum = arr[0]

while ed < n:
    if sum >= s: # 합이 넘으면 st 한 칸 이동
        ans = min(ans, ed - st + 1)

        sum -= arr[st]
        if st == ed:
            ed += 1
        st += 1
    else: # 합이 안 넘으면 ed 한 칸 이동
        ed += 1
        if ed < n:
            sum += arr[ed]

if ans == 1e9:
    ans = 0

print(ans)