import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
ord = [0 for i in range(n + 1)]
for i in range(n):
    ord[arr[i]] = i

mx = 0
cnt = 1
for i in range(2, n + 1):
    if ord[i-1] < ord[i]:
        cnt += 1
    else:
        mx = max(mx, cnt)
        cnt = 1 
mx = max(mx, cnt)
print(n - mx)