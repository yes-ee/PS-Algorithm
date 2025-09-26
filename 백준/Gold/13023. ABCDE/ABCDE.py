n, m = map(int, input().split())
arr = [[] for i in range(n)]

for i in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)

def sol(n, m, arr):
    ans = 0
    vis = [0 for i in range(n)]

    def dfs(x, vis, cnt):
        nonlocal ans
        
        if ans:
            return
        
        if cnt == 5:
            ans = 1
            return
            
        for nx in arr[x]:
            if vis[nx]:
                continue

            vis[nx] = 1
            dfs(nx, vis, cnt + 1)
            vis[nx] = 0

    for i in range(n):
        vis[i] = 1
        dfs(i, vis, 1)
        vis[i] = 0
    return ans

print(sol(n, m, arr))