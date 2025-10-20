arr = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]

a, b = map(int, input().split())
result = []
for i in range(a, b + 1):
    num = "" 
    if len(str(i)) == 1:
        num = arr[i]
    elif len(str(i)) == 2:
        num = arr[i // 10] + arr[i % 10]
    
    result.append((num, i))

result.sort()
for i in range(len(result)):
    print(result[i][1], end=' ')
    if i % 10 == 9:
        print()