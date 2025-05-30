import sys

input = sys.stdin.readline

n, m = map(int, input().split())
name = {}
num = {}
for i in range(n):
    a = input().strip()
    name[a] = i+1
    num[i+1] = a

for i in range(m):
    a = input().strip()
    if a.isalpha():
        print(name[a])
    else:
        print(num[int(a)])