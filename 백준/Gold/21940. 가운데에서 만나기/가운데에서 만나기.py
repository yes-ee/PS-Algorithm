# floyd

import sys
input = sys.stdin.readline
INF = 987654321

n, m = map(int, input().split())
arr = [[INF for i in range(n + 1)] for j in range(n + 1)]

for i in range(m):
    a, b, c = map(int, input().split())
    arr[a][b] = c

k = int(input())
citys = list(map(int, input().split())) # 출발 도시

for i in range(1, n + 1):
    arr[i][i] = 0

# 각 도시 별 최단 경로 구하기
for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if arr[i][j] > (arr[i][k] + arr[k][j]):
                arr[i][j] = arr[i][k] + arr[k][j]

# 각 도시별 왕복시간 최소값
times = [INF]

for i in range(1, n + 1):
    mx = 0
    for city in citys:
        mx = max(mx, arr[city][i] + arr[i][city])
    times.append(mx)

mx_time = min(times)
ans = []

for i in range(1, n + 1):
    if times[i] == mx_time:
        ans.append(i)

print(*ans)