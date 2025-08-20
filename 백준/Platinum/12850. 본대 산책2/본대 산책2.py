import sys
input = sys.stdin.readline

d = int(input())

m = [[0,1,1,0,0,0,0,0],
     [1,0,1,1,0,0,0,0],
     [1,1,0,1,1,0,0,0],
     [0,1,1,0,1,1,0,0],
     [0,0,1,1,0,1,0,1],
     [0,0,0,1,1,0,1,0],
     [0,0,0,0,0,1,0,1],
     [0,0,0,0,1,0,1,0]]

l = 8

def mul(m1, m2):
    ret = []
    for i in range(l):
        tmp = []
        for j in range(l):
            sum = 0
            for k in range(l):
                sum += m1[i][k] * m2[k][j]
            tmp.append(sum % 1000000007)
        ret.append(tmp)

    return ret

def pow_matrix(n):
    if n == 1:
        return m
    mm = pow_matrix(n//2)

    if n % 2 == 0:
        return mul(mm, mm)
    else:
        return mul(mul(mm, mm), m)

ans = pow_matrix(d)
print(ans[0][0])