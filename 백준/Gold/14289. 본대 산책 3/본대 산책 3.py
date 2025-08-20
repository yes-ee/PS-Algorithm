import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[0 for j in range(n)] for i in range(n)]

for i in range(m):
    a, b = map(int, input().split())
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1

d = int(input())

# 행렬 곱셈
def mul(m1, m2):
    ret = []
    for i in range(n):
        tmp = []
        for j in range(n):
            sum = 0
            for k in range(n):
                sum += m1[i][k] * m2[k][j]
            tmp.append(sum % 1000000007)
        ret.append(tmp)

    return ret

# 거듭제곱
def exp(x):
    if x == 1:
        return graph
    half = exp(x//2)
    ret = mul(half, half)

    if x & 1:
        ret = mul(ret, graph)

    return ret

ans = exp(d)
print(ans[0][0])