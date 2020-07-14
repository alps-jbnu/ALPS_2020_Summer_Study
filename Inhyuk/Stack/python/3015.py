import sys

N = int(input())

ans = 0
stack = []

for _ in range(N):
    M = int(sys.stdin.readline()[:-1])
    while stack and stack[-1][0] < M:
        ans += stack[-1][1]
        stack.pop()
    if stack:
        if M == stack[-1][0]:
            stack.append((M, stack.pop()[1]+1))
            if len(stack) == 1:
                ans += stack[-1][1] - 1
            else:
                ans += stack[-1][1]
        else:
            ans += 1
            stack.append((M, 1))
    else:
        stack.append((M, 1))

print(ans)
