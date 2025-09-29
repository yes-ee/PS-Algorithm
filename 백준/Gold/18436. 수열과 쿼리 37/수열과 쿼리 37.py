# segtree

import sys, math  
input = sys.stdin.readline  
sys.setrecursionlimit(100000)  

# 처음 arr 기반으로 트리 초기화
def init(arr, tree, node, st, ed):
    if st == ed:
        tree[node] = arr[st]
        return

    init(arr, tree, node * 2, st, (st + ed) // 2)
    init(arr, tree, node * 2 + 1, (st + ed) // 2 + 1, ed)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]

# 값, 구간값 업데이트
def update(arr, tree, node, st, ed, idx, val):
    if idx < st or idx > ed:
        return
    if st == ed:
        arr[idx] = val % 2
        tree[node] = val % 2
        return
    
    update(arr, tree, node * 2, st, (st + ed) // 2, idx, val)
    update(arr, tree, node * 2 + 1, (st + ed) // 2 + 1, ed, idx, val)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]

# 쿼리
def query(tree, node, st, ed, left, right):
    if left > ed or right < st:
        return 0
    if left <= st and ed <= right:
        return tree[node]
    lsum = query(tree, node * 2, st, (st + ed) // 2, left, right)
    rsum = query(tree, node * 2 + 1, (st + ed) // 2 + 1, ed, left, right)
    return lsum + rsum

n = int(input())
arr = list(map(int, input().split()))
for i in range(n):
    arr[i] = arr[i] % 2

h = math.ceil(math.log2(n))
tree_size = 1 << (h + 1)
tree = [0 for i in range(tree_size)]
init(arr, tree, 1, 0, n-1)

m = int(input())
for i in range(m):
    cmd, a, b = map(int, input().split())
    if cmd == 1:
        update(arr, tree, 1, 0, n-1, a-1, b)
    elif cmd == 2:
        print(b - a + 1 - query(tree, 1, 0, n-1, a-1, b-1))
    elif cmd == 3:
        print(query(tree, 1, 0, n-1, a-1, b-1))
