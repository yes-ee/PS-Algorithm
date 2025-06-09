import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = [0 for i in range(1000001)]
for i in range(n):
    a, b = map(int, input().split())
    arr[a] += 1
    arr[b] -= 1

for i in range(1000000):
    arr[i + 1] += arr[i]

st, ed = 0, 0
sum = arr[ed]
fin = 0
while st < 1000001 and ed <= 1000001:
    if sum == k:
        print(st, ed + 1)
        fin = 1
        break
    elif sum < k:
        ed += 1
        if ed < 1000001:
            sum += arr[ed]
    else:
        sum -= arr[st]
        st += 1

if not fin:
    print(0, 0)