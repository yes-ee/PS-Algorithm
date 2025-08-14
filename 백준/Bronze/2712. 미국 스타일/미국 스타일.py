import sys
input = sys.stdin.readline

t = int(input())

for i in range(t):
    tmp = list(map(str, input().split()))
    num = float(tmp[0])
    unit = tmp[1]

    if unit == "kg":
        num = num * 2.2046
        print("{:.4f}".format(num), end=' ')
        print("lb")
    elif unit == "lb":
        num = num * 0.4536
        print("{:.4f}".format(num), end=' ')
        print("kg")
    elif unit == "l":
        num = num * 0.2642
        print("{:.4f}".format(num), end=' ')
        print("g")
    else:
        num = num * 3.7854
        print("{:.4f}".format(num), end=' ')
        print("l")