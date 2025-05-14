# 1 2 3 4
# 1 2 3
# 1 2
# 1 2 5 6
# 1 2 5
# 1 2 5 7 8
# 1 2 5 7
# 1 2 
# 1
# -

# 현재 스택의 맨 위에 있는 수 >  뽑아야 하는 수 이면 불가능
# 스택 맨 위 = 뽑아야 하는 수 => pop 연산 (-)
# 스택 맨 위 < 뽑아야 하는 수 => 뽑아야 하는 수까지 push, 맨 위 pop

import sys

n = sys.stdin.readline()
st = []
ans = []
end = 0
idx = 1

for _ in range(int(n)):
    num = sys.stdin.readline()
    num = int(num)
    if len(st) == 0 or st[-1] != num:
        if idx > int(num):
            end = 1
            break
        while True:
            st.append(idx)
            ans.append("+")
            idx += 1
            if (st[-1] == num):
                st.pop()
                ans.append("-")
                break
    elif st[-1] == int(num):
        st.pop()
        ans.append("-")
        
if end == 1:
    print("NO")
else:
    for c in ans:
        print(c)