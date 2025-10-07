import sys
import heapq as hq
input = sys.stdin.readline
push = hq.heappush
pop = hq.heappop

n, d = map(int, input().split())
arr = list(map(int, input().split()))

dp = [0 for i in range(n)]
heap = []

for i in range(n):
    val, idx = arr[i], i
    # 범위 밖인 거 pop
    while heap:
        val, idx = heap[0]
        val *= -1
        val += arr[i]
        if idx < i - d:
            pop(heap)
        else:
            break
    
    # dp, pq에 값 추가
    max_val = max(val, arr[i])
    dp[i] = max_val
    push(heap, (-max_val, i))

print(max(dp))