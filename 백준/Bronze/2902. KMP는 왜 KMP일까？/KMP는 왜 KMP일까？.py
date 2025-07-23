import sys
input = sys.stdin.readline

s = input().strip()
words = s.split('-')
ans = ""
for word in words:
    ans += word[0]

print(ans)