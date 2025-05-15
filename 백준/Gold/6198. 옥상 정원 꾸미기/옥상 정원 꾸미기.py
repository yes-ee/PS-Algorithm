import sys

n = int(sys.stdin.readline())
st = []
arr = []
sum = 0
ans = [0 for _ in range(n)]

for i in range(n):
    num = int(sys.stdin.readline())
    arr.append(num)
    # 스택에서 num보다 작은 수 pop
    while len(st) != 0 and arr[st[-1]] <= num:
        ans[st[-1]] = i - st[-1] -1
        st.pop()

    st.append(i)

while len(st) != 0:
    ans[st[-1]] = n - st[-1] -1
    st.pop()

for i in ans:
    sum += i

print(sum)
