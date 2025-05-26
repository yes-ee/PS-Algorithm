import sys
input = sys.stdin.readline

s, k = map(int, input().split())
ans = 1

num = s // k
for i in range(s % k):
    ans *= (num + 1)
for i in range(k - s % k):
    ans *= num
print(ans)