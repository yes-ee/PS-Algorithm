import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
st = []
ans = [0 for i in range(n)]

for i in range(n):
    num = arr[i]
    # num보다 작은 수 pop
    while len(st) != 0 and arr[st[-1]] < num:
        ans[st[-1]] = num
        st.pop()

    st.append(i)

while len(st) != 0:
    ans[st[-1]] = -1
    st.pop()

for i in ans:
    print(i, end=' ')