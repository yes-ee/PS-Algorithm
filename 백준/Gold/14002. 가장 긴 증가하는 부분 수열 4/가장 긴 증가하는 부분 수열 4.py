import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

dp = [1] * n
dp_idx = [-1] * n

for i in range(1, n):
    mx = 0
    idx = -1
    for j in range(i):
        # arr[i]보다 작은 수 중 max dp 값 찾기
        if arr[j] < arr[i]:
            if dp[j] > mx:
                mx = dp[j]
                idx = j
    dp[i] = mx + 1
    dp_idx[i] = idx

mx = dp[0]
idx = 0
for i in range(1, n):
    if dp[i] > mx:
        mx = dp[i]
        idx = i

ans = []
while idx != -1:
    ans.append(arr[idx])
    idx = dp_idx[idx]

print(mx)
for i in ans[::-1]:
    print(i, end=' ')
