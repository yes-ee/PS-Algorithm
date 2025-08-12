import heapq as hq
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))

h = []
length = (m-1) << 1
ans = []

for i in range(min(n, length + 1)):
    hq.heappush(h, (-arr[i], i))

ans.append(-h[0][0])

for i in range(1, n - length):
    hq.heappush(h, (-arr[i+length], i+length))

    while h and h[0][1] < i:
        hq.heappop(h)

    ans.append(-h[0][0])

print(' '.join(map(str, ans)))