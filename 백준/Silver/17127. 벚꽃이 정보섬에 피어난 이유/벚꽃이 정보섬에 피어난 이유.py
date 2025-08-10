import sys
input = sys.stdin.readline

n = int(input())
trees = list(map(int, input().split()))
ans = 0

def get_mul(a, b):
    ret = 1
    for i in range(a, b + 1):
        ret *= trees[i]
    return ret

for i in range(n-3):
    sum = get_mul(0, i)
    for j in range(i+1, n-2):
        sum += get_mul(i+1, j)
        for k in range(j+1, n-1):
            sum += get_mul(j+1, k)
            sum += get_mul(k+1, n-1)
            ans = max(ans, sum)
            sum -= get_mul(k+1, n-1)
            sum -= get_mul(j+1, k)
        sum -= get_mul(i+1, j)

print(ans)