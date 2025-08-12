import heapq as hq
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))

h = []
length = 2 * (m-1)
ans = []

# 첫 길이 추가
for i in range(min(n, length + 1)):
    hq.heappush(h, (-arr[i], i))

ans.append(-h[0][0])

for i in range(1, n - length):
    hq.heappush(h, (-arr[i+length], i+length))

    while h and h[0][1] < i:
        hq.heappop(h)

    ans.append(-h[0][0])

for i in ans:
    print(i, end=' ')