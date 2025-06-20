# floyd
# path 저장

import sys
input = sys.stdin.readline
INF = 987654321

n, m = map(int, input().split())
arr = [[INF for i in range(n + 1)] for j in range(n + 1)]
p = [[-1 for i in range(n + 1)] for j in range(n + 1)]

for i in range(m):
    a, b, c = map(int, input().split())
    arr[a][b] = c
    arr[b][a] = c
    p[a][b] = b
    p[b][a] = a

# 거리 업데이트, 경로 같이 저장
for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if arr[i][j] > (arr[i][k] + arr[k][j]):
                arr[i][j] = arr[i][k] + arr[k][j]
                p[i][j] = p[i][k]

# 출력
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j:
            print("-", end=' ')
            continue
        print(p[i][j], end=' ')
    print()