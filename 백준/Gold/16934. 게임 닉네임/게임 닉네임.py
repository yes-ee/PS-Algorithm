# trie

import sys
input = sys.stdin.readline

n = int(input())

unused = 2
ROOT = 1
nxt = [[-1 for j in range(26)] for i in range(n * 10 + 5)]
chk = [0 for i in range(n * 10 + 5)]

def insert(s):
    global unused
    cur = ROOT
    for c in s:
        c = ord(c) - ord('a')
        if nxt[cur][c] == -1:
            nxt[cur][c] = unused
            unused += 1
            # chk[cur] = 1
        cur = nxt[cur][c]
    chk[cur] += 1

def find(s):
    cur = ROOT
    for i in range(len(s)):
        c = s[i]
        c = ord(c) - ord('a')
        if nxt[cur][c] == -1:
            print(s[:i+1])
            return
        cur = nxt[cur][c]
    num = chk[cur] + 1
    if chk[cur] == 0:
        print(s)
    else: # 동일 단어가 존재
        print(s + str(num))

for i in range(n):
    s = input().strip()
    # 추가하면서 별칭 출력
    find(s)
    insert(s)