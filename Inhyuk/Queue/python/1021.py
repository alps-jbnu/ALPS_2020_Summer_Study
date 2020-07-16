import sys
from collections import deque

N, K = map(int, input().split())
dq = deque(range(1, N+1))
ans = 0

target = deque(map(int, sys.stdin.readline().split()))

for _ in range(K):
    cnt = 0
    while dq[0] != target[0]:
        dq.append(dq.popleft())
        cnt += 1
    ans += cnt if cnt < len(dq)-cnt else len(dq)-cnt
    dq.popleft()
    target.popleft()

print(ans)
