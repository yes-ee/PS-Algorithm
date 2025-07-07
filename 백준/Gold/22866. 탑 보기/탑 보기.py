import sys
input=sys.stdin.readline

n = int(input())
st = []
h = list(map(int, input().split()))
ans = [[100001, 100001] for i in range(n)]

# 왼쪽부터 확인
for i in range(n):
    # 스택에서 현재보다 작은 탑 다 pop
    cur = h[i]
    while st:
        if st[-1][0] <= cur: st.pop()
        else: break

    # 볼 수 있는 탑 개수 갱신
    ans[i][0] = len(st)

    # 가장 가까운 값 갱신
    if st:
        ans[i][1] = st[-1][1]

    # 스택에 추가
    st.append((cur, i + 1))

st = []
# 오른쪽부터 확인
for i in range(n-1, -1, -1):
    # 스택에서 현재보다 작은 탑 다 pop
    cur = h[i]
    while st:
        if st[-1][0] <= cur: st.pop()
        else: break

    # 볼 수 있는 탑 개수 갱신
    ans[i][0] += len(st)

    # 가장 가까운 값 갱신
    if st and abs(i + 1 - ans[i][1]) > abs(st[-1][1] - i - 1):
        ans[i][1] = st[-1][1]

    # 스택에 추가
    st.append((cur, i + 1))

for i in range(n):
    if ans[i][1] == 100001:
        print(ans[i][0])
    else:
        print(ans[i][0], ans[i][1])