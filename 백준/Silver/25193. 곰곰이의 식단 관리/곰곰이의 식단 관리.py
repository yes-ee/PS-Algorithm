import sys
input = sys.stdin.readline

n = int(input())
s = input().strip()
dic = {'C':0, 'E':0}

for c in s:
    if c != 'C':
        c = 'E'
    dic[c] += 1

c = dic['C']
e = dic['E']

if c % (e + 1) != 0:
    print(c // (e + 1) + 1)
else:
    print(c // (e + 1))