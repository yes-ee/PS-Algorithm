import sys
input = sys.stdin.readline

t, n, d = map(int, input().split())
DIV = 1000000007
mat_list = []
for i in range(t):
    m = int(input())
    adjs = [[0 for i in range(n)] for j in range(n)]
    for j in range(m):
        a, b, c = map(int, input().split())
        adjs[a-1][b-1] = c
    mat_list.append(adjs)

ans = [[1 if i == j else 0 for i in range(n)] for j in range(n)]

if d == 0:
    for i in range(n):
        for j in range(n):
            if i == j:
                print("1", end=" ")
            else:
                print("0", end=" ")
        print()
    exit(0)
k = d // t
lft = d % t

def mul(m1, m2):
    ret = []
    for i in range(n):
        tmp = []
        for j in range(n):
            sum = 0
            for k in range(n):
                sum += m1[i][k] * m2[k][j]
            tmp.append(sum % DIV)
        ret.append(tmp)
    return ret

def exp(cnt):
    if cnt == 1:
        return mm

    half = exp(cnt // 2)
    ret = mul(half, half)
    if cnt & 1:
        ret = mul(ret, mm)
    return ret

mm = mat_list[0]
for i in range(1, t):
    mm = mul(mm, mat_list[i])

if k:
    ans = exp(k)
    for i in range(lft):
        ans = mul(ans, mat_list[i])
else:
    ans = mat_list[0]
    for i in range(1, lft):
        ans = mul(ans, mat_list[i])

for i in range(n):
    for j in range(n):
        print(ans[i][j], end=" ")
    print()
