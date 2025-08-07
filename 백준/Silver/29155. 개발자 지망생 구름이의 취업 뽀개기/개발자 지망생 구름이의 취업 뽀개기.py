import sys
input = sys.stdin.readline

n = int(input())

cnts = [0] + list(map(int, input().split()))
problems = [[] for i in range(6)]
ans = 0

for i in range(n):
    k, t = map(int, input().split())
    problems[k].append(t)

for i in range(1, 6):
    dif = problems[i]
    dif.sort()
    ans += dif[0]
    for j in range(1, cnts[i]):
        ans += dif[j] - dif[j-1] + dif[j]

ans += 60 * 4
print(ans)