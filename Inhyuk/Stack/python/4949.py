import sys

while True:
    msg = sys.stdin.readline()[:-1]
    if msg == '.':
        break
    msg = list(msg)
    flag = False
    stack = []
    for ch in msg:
        if ch == '(' or ch == '[':
            stack.append(ch)
        elif ch == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                flag = True
                break
        elif ch == ']':
            if stack and stack[-1] == '[':
                stack.pop()
            else:
                flag = True
                break
    if not flag and not stack:
        print('yes')
    else:
        print('no')
