import sys
input = sys.stdin.readline

k, l = map(int, input().split())
dic = {}

for i in range(l):
    s = input().strip()
    dic[s] = i

d = sorted(dic.keys(), key=lambda x: dic[x])
k = min(k, len(d))

for i in range(k):
    print(d[i])