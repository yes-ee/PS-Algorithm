import sys
input = sys.stdin.readline

n = int(input())
arr = []
vis = [[0 for i in range(n)] for j in range(n)]
barr = []   # 흑색 판
warr = []   # 백색 판
sum = 0
ans = 0

# input
for i in range(n):
    ln = list(map(int, input().split()))
    arr.append(ln)

for i in range(n):
    for j in range(n):
        if arr[i][j] == 0:
            continue
        if (i + j) % 2 == 0:
            barr.append((i, j))
        else:
            warr.append((i, j))

def init():
    global ans
    ans = 0
    for i in range(n):
        for j in range(n):
            vis[i][j] = 0

def check(x, y):
    for i in range(n):
        for j in range(n):
            if vis[i][j] == 1 and abs(x - i) == abs(y - j):
                return False
    return True

def dfs(idx, ar, cnt):
    global ans

    for k in range(idx, len(ar)):
        i, j = ar[k]

        if not check(i, j):
            continue
        
        vis[i][j] = 1
        ans = max(ans, cnt + 1)
        dfs(k + 1, ar, cnt + 1)
        vis[i][j] = 0

dfs(0, barr, 0)
sum = ans
init()
dfs(0, warr, 0)
sum += ans
print(sum)