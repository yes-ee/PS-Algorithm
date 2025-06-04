import sys
from gc import get_count

input = sys.stdin.readline

n, m, l = map(int, input().split())
arr = []
if n != 0:
    arr= list(map(int, input().split()))
arr.append(0)
arr.append(l)
arr= sorted(arr)

def check(num):
    sum = 0
    for d in dis:
        sum += (d - 1) // num

    return sum <= m

# 구간 별 길이 계산
dis = []
mx = 0
for i in range(n + 1):
    dif = arr[i+1] - arr[i]
    dis.append(dif)
    mx = max(mx, dif)

for i in range(1, mx + 1):
    # 필요한 개수 확인
    if check(i):
        print(i)
        break