import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))

st, ed = 0, 0
ans, cnt = 0, 0

while ed < n:
    if arr[ed] % 2 == 1: # 홀수
        # k 남아있으면 이동
        if k > 0:
            k -= 1
            ed += 1
        # k 없으면 st 땡기기
        else:
            if arr[st] % 2 == 0:
                cnt -= 1
            else:
                k += 1
            st += 1
    else: # 짝수
        cnt += 1
        ans = max(ans, cnt)
        ed += 1
    
print(ans)