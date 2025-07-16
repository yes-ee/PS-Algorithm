from collections import deque

def solution(board):
    ans = 0
    blocks = [] # (블록 번호, (직사각형 좌하단/우상단 점))
    n = len(board)
    
    # 블록 번호, 직사각형 좌하단/우상단 점 저장
    def bfs(x, y):
        grp = board[x][y] # 블록 번호
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        x1, y1 = x, y
        x2, y2 = x, y

        q = deque()
        q.append((x, y))
        vis[x][y] = 1
        
        while q:
            cur = q.popleft()
            x = cur[0]; y = cur[1]
            x1 = min(x1, x); y1 = min(y1, y)
            x2 = max(x2, x); y2 = max(y2, y)
            
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                
                if 0 <= nx < n and 0 <= ny < n:
                    if vis[nx][ny]: continue
                    if board[nx][ny] != grp: continue
                    vis[nx][ny] = 1
                    q.append((nx, ny))

        blocks.append((grp, ((x1, y1), (x2, y2))))

    # bfs로 각 블록 위치 저장
    vis = [[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            if vis[i][j]: continue
            if board[i][j] == 0: continue
            bfs(i, j)

    # print(blocks)
    
    # 블록 돌면서 없앨 수 있는 블록 있는지 확인
    chk = [0 for i in range(201)] # 체크 여부
    chg = 1
    while chg:
        chg = 0
        # print("--------------")
        # for i in range(n):
        #     print(board[i])
        
        for i in range(len(blocks)):
            grp = blocks[i][0]
            if chk[grp]: continue
            x1, y1 = blocks[i][1][0]
            x2, y2 = blocks[i][1][1]
            fin = 0
            
            # print(x1, y1, x2, y2, grp)

            # 못 가는 위치면 끝
            for i in range(x1, x2 + 1):
                if fin: break
                for j in range(y1, y2 + 1):
                    if board[i][j] != 0 and board[i][j] != grp:
                        fin = 1
                        break
                    if board[i][j] == 0: # 위에 확인
                        for k in range(0, i):
                            if board[k][j] != 0:
                                fin = 1
                                break

            if not fin:
                # print(grp)
                chg = 1
                chk[grp] = 1
                ans += 1
                for i in range(x1, x2 + 1):
                    for j in range(y1, y2 + 1):
                        board[i][j] = 0
                # print(grp, board)
                break
    return ans
