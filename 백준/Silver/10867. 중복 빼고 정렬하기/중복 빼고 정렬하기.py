import sys
input = sys.stdin.readline

n = int(input())
dic = dict()
lst = list(map(int, input().split()))

for num in lst:
    dic[num] = dic.get(num, 0) + 1

ans = sorted(dic.keys())

print(*ans)