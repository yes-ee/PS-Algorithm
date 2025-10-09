import sys
input = sys.stdin.readline

h, w = map(int, input().split())
for i in range(h):
    ans = [-1 for i in range(w)]
    arr = input().strip()
    for j in range(w-1, -1, -1):
        if arr[j] != 'c':
            continue
        for k in range(0, w - j):
            idx = j + k
            if ans[idx] == -1:
                ans[idx] = k
    for cur in ans:
        print(cur, end = ' ')
    print()