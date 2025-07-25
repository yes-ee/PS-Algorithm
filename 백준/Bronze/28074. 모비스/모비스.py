import sys
input=sys.stdin.readline

s = input().strip()
ss = set(s)
word = "MOBIS"

for c in word:
    if c not in ss:
        print("NO")
        exit(0)

print("YES")