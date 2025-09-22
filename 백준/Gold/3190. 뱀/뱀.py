import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
k = int(input())

# 사과 입력
arr = [[0 for i in range(n)] for j in range(n)]
for i in range(k):
    a, b = map(int, input().split())
    arr[a-1][b-1] = 1 # 사과 존재 시 1

# 방향 전환
l = int(input())
changes = deque()
for i in range(l):
    time, dir = map(str, input().split())
    changes.append((int(time), dir))

# dir: 0, 1, 2, 3 (위, 오, 아, 왼)
cur_dir = 1
x, y = 0, 0
time = 1
snake = deque()
snake.append((0, 0))

def move(x, y, cur_dir):
    nx, ny = x, y
    if cur_dir == 0:
        nx -= 1
    elif cur_dir == 2:
        nx += 1
    elif cur_dir == 1:
        ny += 1
    else:
        ny -= 1
    return nx, ny

def check_possible(x, y):
    # 범위 내인지, 뱀 안 겹치는지 확인
    if 0 <= x < n and 0 <= y < n and arr[x][y] != 2:
        return True
    return False

def change_dir(cur_dir, ch_dir):
    nx_dir = cur_dir
    if ch_dir == 'L':
        nx_dir = (cur_dir - 1) % 4
    else:
        nx_dir = (cur_dir + 1) % 4
    return nx_dir

while True:
    # 1. 현재 방향으로 1 이동
    x, y = move(x, y, cur_dir)
    if not check_possible(x, y):
        print(time)
        exit(0)
    
    # 2-1. 이동한 곳에 사과가 있다면
    if arr[x][y] == 1:
        arr[x][y] = 2
        snake.appendleft((x, y))
    # 2-2. 이동한 곳에 사과가 없다면
    else:
        if len(snake) > 1:
            sx, sy = snake[-1]
            arr[sx][sy] = 0
            arr[x][y] = 2
            snake.appendleft((x, y))
            snake.pop()

    # 3. 방향 변환
    if changes:
        ch_time, ch_dir = changes[0]
        if ch_time == time:
            cur_dir = change_dir(cur_dir, ch_dir)
            changes.popleft()

    # 4. 시간 증가
    time += 1