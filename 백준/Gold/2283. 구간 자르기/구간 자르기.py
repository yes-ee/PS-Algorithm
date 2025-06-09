import sys
input = sys.stdin.readline

n, k = map(int, input().split())
dic = dict()
arr = []
for i in range(n):
    a, b = map(int, input().split())
    arr.append((a, 1))
    arr.append((b, -1))

arr.sort()

l = arr[0][0]
r = arr[-1][0]

# 딕셔너리 생성
pre = 0
cnt = 0
arr.append((r + 1, 0))
for cur, tp in arr:
    for i in range(pre, cur):
        dic[i] = cnt
    pre = cur
    cnt += tp

st, ed = 0, 0
sum = dic[ed]
fin = 0
while st < r and ed <= r:
    if sum == k:
        print(st, ed + 1)
        fin = 1
        break
    elif sum < k:
        ed += 1
        if ed < r:
            sum += dic[ed]
    else:
        sum -= dic[st]
        st += 1

if not fin:
    print(0, 0)