import sys

st = []
sum = 0

k = int(sys.stdin.readline())

for _ in range(k):
    n = int(sys.stdin.readline())
    if n == 0: #pop
        st.pop()
    else:
        st.append(n)

for i in range(len(st)):
    sum += st[i]

print(sum)