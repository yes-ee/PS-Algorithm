n = int(input())
arr = list(map(int, input().split()))
seats = [0 for i in range(101)]
cnt = 0
for num in arr:
    if seats[num] == 1:
        cnt += 1
    else:
        seats[num] = 1
print(cnt)