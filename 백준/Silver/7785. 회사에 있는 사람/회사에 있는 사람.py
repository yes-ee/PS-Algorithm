import sys
input = sys.stdin.readline

n = int(input())
s = set()
for i in range(n):
    a, b = input().split()
    if b == "enter":
        s.add(a)
    else:
        s.remove(a)

ans = list(s)
ans.sort(reverse=True)

for c in ans:
    print(c)