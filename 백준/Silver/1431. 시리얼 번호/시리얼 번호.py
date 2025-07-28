import sys
input=sys.stdin.readline

n = int(input())
arr = []

for i in range(n):
    s = input().strip()
    sum = 0
    for c in s:
        sum += ord(c) - ord('0') if c.isnumeric() else 0
    arr.append((s, sum))

arr.sort(key=lambda x: (len(x[0]), x[1], x[0]))

for x in arr:
    print(x[0])