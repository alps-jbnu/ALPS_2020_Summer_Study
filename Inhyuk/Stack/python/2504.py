A = list(input())
stack = []
flag = False
for ch in A:
    if ch == '(':
        stack.append('(')
    elif ch == ')':
        if not '(' in stack:
            flag = True
            break
        elif stack[-1] == '(':
            stack.pop()
            stack.append(2)
        elif isinstance(stack[-1], int):
            temp = stack.pop()
            while isinstance(stack[-1], int):
                temp += stack.pop()
            if stack[-1] == '(':
                stack.pop()
                stack.append(2*temp)
    elif ch == '[':
        stack.append('[')
    elif ch == ']':
        if not '[' in stack:
            flag = True
            break
        elif stack[-1] == '[':
            stack.pop()
            stack.append(3)
        elif isinstance(stack[-1], int):
            temp = stack.pop()
            while isinstance(stack[-1], int):
                temp += stack.pop()
            if stack[-1] == '[':
                stack.pop()
                stack.append(3*temp)

if flag or '(' in stack or '[' in stack:
    print(0)
else:
    ans = stack.pop()
    while stack:
        ans += stack.pop()
    print(ans)
