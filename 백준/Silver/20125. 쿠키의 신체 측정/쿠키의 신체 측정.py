n = int(input())
arr = []
for i in range(n):
    s = input().strip()
    arr.append(s)

head = (-1, -1)
for i in range(n):
    if head[0] != -1:
        break
    for j in range(n):
        if arr[i][j] == '*':
            head = (i, j)
            break

heart = (head[0] + 1, head[1])
waist = (heart[0] + 1, heart[1])
for i in range(heart[0] + 1, n):
    if arr[i][heart[1]] == '*':
        waist = (i, heart[1])
    else:
        break
left_arm = 0
right_arm = 0
left_leg = 0
right_leg = 0
for i in range(0, heart[1]):
    if arr[heart[0]][i] == '*':
        left_arm += 1
for i in range(heart[1] + 1, n):
    if arr[heart[0]][i] == '*':
        right_arm += 1
for i in range(waist[0] + 1, n):
    if arr[i][waist[1] - 1] == '*':
        left_leg += 1
for i in range(waist[0] + 1, n):
    if arr[i][waist[1] + 1] == '*':
        right_leg += 1
print(heart[0]+1, heart[1]+1)
print(left_arm, right_arm, (waist[0] - heart[0]), left_leg, right_leg)