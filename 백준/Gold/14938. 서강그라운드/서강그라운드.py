# floyd

import sys
input = sys.stdin.readline
INF = 987654321

n, m, r = map(int, input().split())
items = [0] + list(map(int, input().split())) # 지역별 아이템 개수
arr = [[INF for i in range(n + 1)] for j in range(n + 1)]

for i in range(r):
    a, b, c = map(int, input().split())
    arr[a][b] = c
    arr[b][a] = c

# init
for i in range(n + 1):
    arr[i][i] = 0

# 전체 최단 거리 갱신 -> 플로이드
for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if arr[i][j] > (arr[i][k] + arr[k][j]):
                arr[i][j] = arr[i][k] + arr[k][j]

# 각 지역에서 갈 수 있는 합 중 최댓값 구하기
ans = 0
for i in range(1, n + 1):
    sum = 0
    for j in range(1, n + 1):
        if arr[i][j] <= m:
            sum += items[j]
    ans = max(ans, sum)

print(ans)