n = int(input())

l = 2 * n - 1

for i in range(n):
    s = [1 for i in range(l - i)]
    for j in range(i):
        s[j] = 0
    for x in s:
        if x == 1:
            print('*', end='')
        else:
            print(' ', end='')
    print()

