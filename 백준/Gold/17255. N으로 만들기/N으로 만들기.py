# dfs

import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

sn = input().strip()
l = len(sn)

ds = [-1, 0]
de = [0, 1]
dic = dict()
cnt = 0

def dfs(s, e, path):
    if s == 0 and e == l - 1:
        dic[path] = 1
        return 

    for i in range(2):
        ns = s + ds[i]
        ne = e + de[i]

        if ns < 0 or ne >= l:
            continue

        nn = sn[ns:ne+1]
        npath = path + nn
        if npath in dic:
            continue

        dfs(ns, ne, npath)

for i in range(l):
    dfs(i, i, sn[i])

print(len(dic))