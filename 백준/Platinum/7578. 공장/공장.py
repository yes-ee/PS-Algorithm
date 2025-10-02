# segment tree

import math
import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

n = int(input())
h = math.ceil(math.log2(n))
tree_size = 1 << (h+1)
tree = [0] * tree_size

arr = [0 for i in range(n)]

def init(tree, arr, node, st, ed):
    if st == ed:
        tree[node] = arr[st]
        return
    init(tree, arr, node * 2, st, (st + ed) // 2)
    init(tree, arr, node * 2 + 1, (st + ed) // 2 + 1, ed)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]

def update(tree, arr, node, st, ed, idx, val):
    if idx < st or idx > ed:
        return
    if st == ed:
        arr[st] = val
        tree[node] = arr[st]
        return
    
    update(tree, arr, node * 2, st, (st + ed) // 2, idx, val)
    update(tree, arr, node * 2 + 1, (st + ed) // 2 + 1, ed, idx, val)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]

def query(tree, node, st, ed, l, r):
    if r < st or l > ed:
        return 0
    if l <= st and ed <= r:
        return tree[node]
    lsum = query(tree, node * 2, st, (st + ed) // 2, l, r)
    rsum = query(tree, node * 2 + 1, (st + ed) // 2 + 1, ed, l, r)
    return lsum + rsum

idx_map = dict()
nums = list(map(int, input().split()))
for i in range(n):
    num = nums[i]
    idx_map[num] = i

nums = list(map(int, input().split()))
ans = 0
for i in range(n):
    num = nums[i]
    idx = idx_map[num]
    ans += query(tree, 1, 0, n-1, idx, n-1)
    update(tree, arr, 1, 0, n-1, idx, 1)

print(ans)
    