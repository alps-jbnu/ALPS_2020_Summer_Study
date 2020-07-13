import sys

n = int(input())
A = list(map(int, sys.stdin.readline().split()))
for i in range(len(A)):
    A[i] = (A[i], i + 1)
stack = []
ans = []

for comp in A:
    if not stack:
        stack.append(comp)
        ans.append(0)
    else:
        while stack:
            if stack[-1][0] > comp[0]:
                ans.append(stack[-1][1])
                stack.append(comp)
                break
            else:
                stack.pop()
        if not stack:
            stack.append(comp)
            ans.append(0)
print(' '.join(map(str, ans)))
