while True:
    n = int(input())
    if n == 0: break

    for i in range(1, n+1):
        for j in range(i):
            print("*", end='')
        print()