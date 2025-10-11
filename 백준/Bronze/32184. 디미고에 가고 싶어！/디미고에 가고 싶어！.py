a, b = map(int, input().split())

ans = 0
if a % 2 == 0:
    a += 1
    ans += 1

ans += (b - a + 2) // 2
print(ans)
