import sys
input = sys.stdin.readline

n = int(input())
ans = 0
visited = [-1] * n

def is_promising(x, y):
    # 세로 확인
    for i in range(x):
        if visited[i] == y:
            return False
    # 대각선 확인
    for i in range(x):
        if abs(x - i) == abs(y - visited[i]):
            return False

    return True

def backtracking(cnt):
    global ans
    if cnt == n:
        ans += 1
        return

    for i in range(n):
        if is_promising(cnt, i):
            visited[cnt] = i
            backtracking(cnt + 1)

mid = n // 2
for i in range(mid):
    visited[0] = i
    backtracking(1)

ans *= 2

if n % 2 == 1:
    visited[0] = mid
    backtracking(1)

print(ans)