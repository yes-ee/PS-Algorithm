import sys
input=sys.stdin.readline

n, m, l, k = map(int, input().split())

arr = []
for i in range(k):
    a, b = map(int, input().split())
    arr.append((a, b))

ans = k
for x, y in arr:
    cnt = k
    mx, my = x + l, y + l # 트램펄린 끝점
    for nx, ny in arr:
        if x <= nx <= mx and y <= ny <= my:
            cnt -= 1
    ans = min(ans, cnt)

for x, y in arr:
    cnt = k
    mx, my = x - l, y + l # 트램펄린 끝점
    for nx, ny in arr:
        if mx <= nx <= x and y <= ny <= my:
            cnt -= 1
    ans = min(ans, cnt)

for x, y in arr:
    cnt = k
    mx, my = x + l, y - l # 트램펄린 끝점
    for nx, ny in arr:
        if x <= nx <= mx and my <= ny <= y:
            cnt -= 1
    ans = min(ans, cnt)

for x, y in arr:
    cnt = k
    mx, my = x - l, y - l # 트램펄린 끝점
    for nx, ny in arr:
        if mx <= nx <= x and my <= ny <= y:
            cnt -= 1
    ans = min(ans, cnt)

# 점 두 개 골라서 확인
for i in range(k):
    for j in range(k):
        if i == j: continue

        x1, y1 = arr[i]
        x2, y2 = arr[j]

        minx, miny = min(x1, x2), min(y1, y2)
        if (minx == x1 and miny == y1) or (minx == x2 and miny == y2):
            ax1, ay1 = min(x1, x2), max(y1, y2) - l
            ax2, ay2 = max(x1, x2) - l, min(y1, y2)

            bx1, by1 = ax1 + l, ay1 + l
            bx2, by2 = ax2 + l, ay2 + l

            cnt = k
            for nx, ny in arr:
                if ax1 <= nx <= bx1 and ay1 <= ny <= by1:
                    cnt -= 1
            ans = min(ans, cnt)

            cnt = k
            for nx, ny in arr:
                if ax2 <= nx <= bx2 and ay2 <= ny <= by2:
                    cnt -= 1
            ans = min(ans, cnt)
        else:
            ax1, ay1 = min(x1, x2), min(y1, y2)
            ax2, ay2 = max(x1, x2) - l, max(y1, y2) - l

            bx1, by1 = ax1 + l, ay1 + l
            bx2, by2 = ax2 + l, ay2 + l

            cnt = k
            for nx, ny in arr:
                if ax1 <= nx <= bx1 and ay1 <= ny <= by1:
                    cnt -= 1
            ans = min(ans, cnt)

            cnt = k
            for nx, ny in arr:
                if ax2 <= nx <= bx2 and ay2 <= ny <= by2:
                    cnt -= 1
            ans = min(ans, cnt)

print(ans)