# segtree

import sys, math
input = sys.stdin.readline
sys.setrecursionlimit(100000)

def init(arr, tree, node, st, ed):
    if st == ed:
        tree[node] = arr[st]
        return

    init(arr, tree, node * 2, st, (st + ed) // 2)
    init(arr, tree, node * 2 + 1, (st + ed) // 2 + 1, ed)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]

def update(arr, tree, node, st, ed, idx, val):
    if idx < st or idx > ed:
        return
    if st == ed:
        tree[node] = val
        arr[idx] = val
        return

    update(arr, tree, node * 2, st, (st + ed) // 2, idx, val)
    update(arr, tree, node * 2 + 1, (st + ed) // 2 + 1, ed, idx, val)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]

def query(tree, node, st, ed, left, right):
    if left > ed or right < st:
        return 0
    if left <= st and ed <= right:
        return tree[node]

    lsum = query(tree, node * 2, st, (st + ed) // 2, left, right)
    rsum = query(tree, node * 2 + 1, (st + ed) // 2 + 1, ed, left, right)
    return lsum + rsum

t = int(input())
nn = 200000
h = math.ceil(math.log2(nn))
tree_size = 1 << (h+1)
tree = [0] * tree_size

for i in range(t):
    n, m = map(int, input().split())
    arr = [0] * nn
    for j in range(n):
        arr[j] = 1
    locations = [n - i - 1 for i in range(n)]

    init(arr, tree, 1, 0, nn-1)
    nums = list(map(int, input().split()))
    for j in range(m):
        num = nums[j]
        print(query(tree, 1, 0, nn-1, locations[num-1] + 1, nn-1), end=' ')
        update(arr, tree, 1, 0, nn-1, locations[num-1], 0)
        locations[num-1] = 100000 + j
        update(arr, tree, 1, 0, nn-1, locations[num-1], 1)
    print()