import sys, math
input = sys.stdin.readline

n = int(input())
arr = [int(input()) for i in range(n)]
arr.sort()

dis = arr[1] - arr[0]
for i in range(2, n):
    dis = math.gcd(dis, arr[i] - arr[i-1])

cnt = 0
for i in range(1, n):
    cnt += (arr[i] - arr[i-1]) // dis - 1

print(cnt)