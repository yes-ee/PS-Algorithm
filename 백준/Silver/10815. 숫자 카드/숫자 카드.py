import sys
input = sys.stdin.readline

n = int(input())
card = set(list(map(int, input().split())))

m = int(input())
nums = list(map(int, input().split()))

for num in nums:
    if num in card:
        print("1", end=' ')
    else:
        print("0", end=' ')
