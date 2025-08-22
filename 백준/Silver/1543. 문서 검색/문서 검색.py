import sys
input = sys.stdin.readline

s = input().strip()
word = input().strip()

l = len(s)
st = 0
cnt = 0

while st < l:
    st = s.find(word, st)
    if st == -1:
        break
    cnt += 1
    st += len(word)

print(cnt)