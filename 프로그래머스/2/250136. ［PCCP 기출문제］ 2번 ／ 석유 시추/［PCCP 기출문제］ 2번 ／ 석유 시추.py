# bfs -> 그룹, 그룹별 크기 저장

from collections import deque

def solution(land):
    ans = 0
    
    n = len(land)
    m = len(land[0])

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    vis = [[0 for j in range(m)] for i in range(n)]
    sum = [0 for i in range(m)]
    
    def bfs(x, y):
        dq = deque()
        vis[x][y] = 1
        dq.append((x, y))
        cnt = 1
        
        cols = set()
        
        while dq:
            x, y = dq.popleft()
            cols.add(y)
            
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                
                if 0 <= nx < n and 0 <= ny < m:
                    if land[nx][ny] == 0 or vis[nx][ny]: continue
                    
                    vis[nx][ny] = 1
                    dq.append((nx, ny))
                    cnt += 1
        
        for col in cols:
            sum[col] += cnt
    
    for i in range(n):
        for j in range(m):
            if land[i][j] == 0 or vis[i][j]: continue
            bfs(i, j)

    return max(sum)

