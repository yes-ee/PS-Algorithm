import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.reverse()

    mx = arr[0]
    sum = 0
    for p in arr:
        if p > mx:
            mx = p
        else:
            sum += (mx - p)

    print(sum)
