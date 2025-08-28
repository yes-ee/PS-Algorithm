# segtree

import sys, math
input = sys.stdin.readline
sys.setrecursionlimit(100000)

# 초기 구간합 구하기
def init(arr, tree, node, st, ed):
    if st == ed:
        tree[node] = arr[st]
        return

    init(arr, tree, node * 2, st, (st + ed) // 2)
    init(arr, tree, node * 2 + 1, (st + ed) // 2 + 1, ed)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]

# 재귀로 올라오면서 값, 구간값 업데이트
def update(arr, tree, node, st, ed, idx, val):
    if idx < st or idx > ed:
        return
    if st == ed:
        arr[idx] = val
        tree[node] = val
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

n, m, k = map(int, input().split())
arr = [int(input()) for _ in range(n)]

h = math.ceil(math.log2(n))
tree_size = 1 << (h+1)
tree = [0] * tree_size

init(arr, tree, 1, 0, n-1)
for i in range(m + k):
    a, b, c = map(int, input().split())
    if a ==1:
        update(arr, tree, 1, 0, n-1, b-1, c)
    else:
        print(query(tree, 1, 0, n-1, b-1, c-1))
