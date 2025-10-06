import sys
input = sys.stdin.readline
n = int(input())
arr = list(map(int, input().split()))

ans = 0

def dfs(cnt, sum):
    global ans
    if cnt == (n-2):
        ans = max(ans, sum)
        return

    for i in range(1, len(arr) - 1):
        energy = arr[i-1] * arr[i+1]
        v = arr.pop(i)
        dfs(cnt + 1, sum + energy)
        arr.insert(i, v)

dfs(0, 0)
print(ans)