import sys

n = sys.stdin.readline()
arr = sys.stdin.readline().split()
st = []
ans = []
n = int(n)
# int 변환
for i in range(n):
    arr[i] = int(arr[i])
    ans.append(0)

for i in range(n-1, -1, -1):
    # 현재 스택에 나보다 작은 거 전부 pop
    while len(st) != 0 and arr[st[-1]] < arr[i]:
        ans[st[-1]] = i + 1
        st.pop()
    st.append(i)

for i in ans:
    print(i, end=' ')