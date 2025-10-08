import sys
input = sys.stdin.readline

n = int(input())
sums = []
for i in range(n):
    sums.append(int(input()))

for i in range(sums[0] + 1):
    arr = [i]
    cur = i
    for j in range(n):
        nxt = sums[j] - cur
        if nxt < 0:
            break
        cur = nxt
        arr.append(nxt)
        if j == n-1 and arr[0] == nxt:
            for k in range(n):
                print(arr[k])
            exit(0)
