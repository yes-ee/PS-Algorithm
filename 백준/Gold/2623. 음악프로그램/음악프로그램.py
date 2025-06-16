# topology sort

# 사이클 발생 시 0 출력
# 사이클 판단 방법
# 큐가 비었는데 ans list 길이 != n이면 -> 사이클

# topology sort

import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

deg = [0 for i in range(n+1)]
adj = [[] for i in range(n+1)]
ans = []
q = deque()

for i in range(m):
    ln = list(map(int, input().split()))
    a = ln[1]
    for j in range(2, ln[0]+1):
        b = ln[j]
        deg[b] += 1
        adj[a].append(b)
        a = b

# indegree 0인 점 찾기
for i in range(1, n+1):
    if deg[i] == 0:
        q.append(i)

# q 순회
while q:
    # 큐에서 꺼내고 ans에 추가
    cur = q.popleft()
    ans.append(cur)

    # q랑 연결된 애들 indegree -1
    for nxt in adj[cur]:
        deg[nxt] -= 1
        if deg[nxt] == 0:
            q.append(nxt)

# 사이클 여부 판단
if len(ans) != n:
    print(0)
else:
    for num in ans:
        print(num)
