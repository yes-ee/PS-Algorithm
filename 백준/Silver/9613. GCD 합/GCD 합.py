from itertools import combinations
import math

t = int(input())

for i in range(t):
    arr = list(map(int, input().split()))
    n = arr[0]
    nums = arr[1:]
    sum = 0

    for a, b in combinations(nums, 2):
        sum += math.gcd(a, b)
    print(sum)
