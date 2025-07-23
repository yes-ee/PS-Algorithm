def solution(board, skills):
    ans = 0
    n = len(board)
    m = len(board[0])
    pre_sum = [[0 for i in range(m + 1)] for j in range(n + 1)]

    for skill in skills:
        tp, r1, c1, r2, c2, degree = skill
        if tp == 1:
            degree *= -1
        
        pre_sum[r1][c1] += degree
        pre_sum[r1][c2 + 1] -= degree
        pre_sum[r2 + 1][c1] -= degree
        pre_sum[r2 + 1][c2 + 1] += degree
        
    for i in range(0, n):
        for j in range(1, m + 1):
            pre_sum[i][j] += pre_sum[i][j-1]

    for j in range(0, m):
        for i in range(1, n + 1):
            pre_sum[i][j] += pre_sum[i-1][j]
            
    for i in range(0, n):
        for j in range(0, m):
            if board[i][j] + pre_sum[i][j] > 0:
                ans += 1
                
    return ans