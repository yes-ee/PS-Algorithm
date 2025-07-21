import sys
input = sys.stdin.readline

n = int(input().strip())
s = input().strip()
l = len(s)
st, ed = 0, -1
ans = 1
dic = dict()

for i in range(l):
    ed = i
    dic[s[i]] = dic.get(s[i], 0) + 1

    if len(dic) > n:
        while st <= ed and len(dic) > n:
            dic[s[st]] -= 1
            if dic[s[st]] == 0:
                dic.pop(s[st])
            st += 1

    ans = max(ans, ed - st + 1)
    ed += 1

ans = max(ans, ed - st)
print(ans)
