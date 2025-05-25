import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
arr = [[' ' for j in range(2 * n)] for i in range(n)]

def recur(x, y, n):
    if n == 3:
        arr[x][y] = '*'
        arr[x+1][y-1] = arr[x+1][y+1] = '*'
        for i in range(-2, 3):
            arr[x+2][y + i] = '*'
        return
    
    recur(x, y, n // 2)
    recur(x + n // 2, y - n // 2, n // 2)
    recur(x + n // 2, y + n // 2, n // 2)

recur(0, n, n)
for i in range(n):
    for j in range(1, 2 * n):
        print(arr[i][j])
    print("\n")