import sys

n = int(sys.stdin.readline())
sum = 0
st = [] # (값, 연속된 숫자의 개수)

for i in range(n):
    num = int(sys.stdin.readline())

    # 같거나 큰 거 나올 때까지 pop
    while st and st[-1][0] < num:
        sum += 1
        st.pop()

    # 스택이 비어있다면 그냥 추가
    if not st:
        st.append((num, 1))
        continue

    # 스택 제일 위의 수가 나보다 큰 수이면
    if st[-1][0] > num:
        sum += 1
        st.append((num, 1))
    # 스택 제일 위의 수가 나와 같으면
    else:
        sum += st[-1][1]
        if len(st) != st[-1][1]:
            sum += 1
        st.append((num, st[-1][1] + 1))

print(sum)