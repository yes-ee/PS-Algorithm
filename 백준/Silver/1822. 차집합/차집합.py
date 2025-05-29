import sys
input = sys.stdin.readline

na, nb = map(int, input().split())
a = set(list(map(int, input().split())))
b = set(list(map(int, input().split())))

c = a - b
print(len(c))

cc = sorted(c)
for n in cc:
    print(n, end=' ')