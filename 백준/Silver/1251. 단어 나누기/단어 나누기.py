# sort

import sys
input = sys.stdin.readline

s = input().strip()
l = len(s)
words = []

for i in range(l):
    for j in range(i + 1, l-1):
        a, b, c = s[:i+1], s[i+1:j+1], s[j+1:]
        res = a[::-1] + b[::-1] + c[::-1]
        words.append(res)

words.sort()
print(words[0])