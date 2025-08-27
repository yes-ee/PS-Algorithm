a1, a0 = map(int, input().split())
c = int(input())
n = int(input())

if c < a1:
    print(0)
elif c == a1:
    if a0 <= n:
        print(1)
    else:
        print(0)
else:
    if (a0 /(c - a1)) <= n:
        print(1)
    else:
        print(0)