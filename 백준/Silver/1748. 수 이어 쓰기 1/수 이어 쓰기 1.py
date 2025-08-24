import sys
input = sys.stdin.readline

sum = [0]
for i in range(1,9):
    sum.append(i * 9 * pow(10, i-1))
n = input().strip()
l = len(n)
n = int(n)

ans = l * (n - pow(10, l-1) + 1)

for i in range(l):
    ans += sum[i]

print(ans)