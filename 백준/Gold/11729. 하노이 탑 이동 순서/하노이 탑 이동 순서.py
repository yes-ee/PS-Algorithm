import sys
input=sys.stdin.readline

def re(n, st, ed):
    if n == 1:
        print(st, ed)
        return

    mid = 6 - st - ed

    re(n-1, st, mid)
    print(st, ed)
    re(n-1, mid, ed)

k = int(input())
print(2 ** k - 1)
re(k, 1, 3)
