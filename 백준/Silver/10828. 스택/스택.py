n = int(input())
st = []

for _ in range(0, n):
    cmd = input().split()
    s = cmd[0]
    if s == "push":
        num = int(cmd[1])
        st.append(num)
    elif s == "pop":
        if len(st) == 0:
            print("-1")
        else:
            print(st[-1])
            st.pop()
    elif s == "size":
        print(len(st))
    elif s == "empty":
        if len(st) == 0:
            print(1)
        else:
            print(0)
    else:
        if len(st) == 0:
            print("-1")
        else:
            print(st[-1])
