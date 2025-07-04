# trie

import sys
input=sys.stdin.readline

n, m = map(int, input().split())

unused = 2
ROOT = 1
MX = 500 * n + 5
nxt = [[-1 for j in range(26)] for i in range(MX)]

def insert(s):
    global unused

    cur = ROOT
    for c in s:
        c = ord(c) - ord('a')
        if nxt[cur][c] == -1:
            nxt[cur][c] = unused
            unused += 1
        cur = nxt[cur][c]

def find(s):
    cur = ROOT
    for c in s:
        c = ord(c) - ord('a')
        if nxt[cur][c] == -1:
            return False
        cur = nxt[cur][c]
    return True

# 트라이에 단어 추가
for i in range(n):
    s = input().strip()
    insert(s)

ans = 0
# 단어 찾기
for i in range(m):
    s = input().strip()
    if find(s):
        ans += 1

print(ans)