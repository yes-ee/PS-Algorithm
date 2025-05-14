import sys

n = sys.stdin.readline()
n = int(n)
st = []
arr = []

for i in range(n):
    num = sys.stdin.readline()
    arr.append(int(num))

st.append(arr[n-1])
for i in range(n-2, -1, -1):
    if arr[i] > st[-1]:
        st.append(arr[i])

print(len(st))
    