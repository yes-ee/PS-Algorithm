import sys
input = sys.stdin.readline

n, m = map(int, input().split())

def recur(n, m):
    # base condition
    if n == 2:
        if m == 0:
            return (1, 1)
        elif m == 1:
            return (1, 2)
        elif m == 2:
            return (2, 2)
        else:
            return (2, 1)

    half = n // 2
    x, y = recur(half, m % (half * half))

    # 해당 사분면 0~3
    lo = m // (half * half)
    if lo == 0:
        return (y, x)
    elif lo == 1:
        return (x, half + y)
    elif lo == 2:
        return (half + x, half + y)
    else:
        return (n + 1 - y, half + 1 - x)

x, y = recur(n, m-1)
print(x, y)