
import sys
from collections import defaultdict

input = sys.stdin.readline

n, m = map(int, input().split())

# 트라이 초기화
trie = defaultdict(dict)

def insert(word):
    node = trie
    for char in word:
        if char not in node:
            node[char] = {}
        node = node[char]

def find(prefix):
    node = trie
    for char in prefix:
        if char not in node:
            return False
        node = node[char]
    return True

# n개의 문자열 트라이에 삽입
for _ in range(n):
    insert(input().strip())

# m개의 문자열이 접두사인지 확인
ans = 0
for _ in range(m):
    if find(input().strip()):
        ans += 1

print(ans)