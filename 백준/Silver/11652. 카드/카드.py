import sys
input = sys.stdin.readline

n = int(input())
dic = dict()
arr = []

for i in range(n):
    num = int(input())
    arr.append(num)

arr = sorted(arr)

for num in arr:
    dic[num] = dic.get(num, 0) + 1

ans = 0
mx = 0

for num, cnt in dic.items():
    if cnt > mx:
        ans = num
        mx = cnt

print(ans)