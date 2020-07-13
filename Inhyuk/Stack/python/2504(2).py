import sys

A = sys.stdin.readline()[:-1]
stack = []

for ch in A:
    if ch == ')':
        temp = 0

        while stack:
            val = stack.pop()
            if val == '(':
                if temp == 0:
                    stack.append(2)
                else:
                    stack.append(2 * temp)
                break
            elif val == '[':
                print(0)
                exit(0)
            else:
                temp += int(val)
    elif ch == ']':
        temp = 0
        while stack:
            val = stack.pop()
            if val == '[':
                if temp == 0:
                    stack.append(3)
                else:
                    stack.append(3 * temp)
                break
            elif val == '(':
                print(0)
                exit(0)
            else:
                temp += val
    else:
        stack.append(ch)

if not '(' in stack and not '[' in stack:
    print(sum(stack))
else:
    print(0)
