n = int(input())
arr = list(map(int, input().split()))
b, c = map(int, input().split())

ans = 0
for stu in arr:
    ans += 1
    stu -= b
    if stu > 0:
        ans += (stu - 1) // c + 1

print(ans)