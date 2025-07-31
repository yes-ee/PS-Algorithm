import sys
input=sys.stdin.readline

x, y, mv_one, mv_two = map(int, input().split())

if mv_one * 2 <= mv_two:
    ans = mv_one * (x + y)
elif mv_one > mv_two:
    ans = mv_two * min(x, y) + mv_two * ((max(x, y) - min(x, y)) // 2) * 2 + mv_one * ((max(x, y) - min(x, y)) % 2)
else:
    ans = mv_two * (min(x, y)) + mv_one * (max(x, y) - min(x, y))

print(ans)