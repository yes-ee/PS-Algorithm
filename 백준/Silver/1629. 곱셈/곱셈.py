import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())

def pow(num, cnt):
    if cnt == 1:
        return num % c

    x = pow(num, cnt // 2)

    if cnt % 2 == 0:
        return x * x % c
    else:
        return x * x * num % c

print(pow(a, b))