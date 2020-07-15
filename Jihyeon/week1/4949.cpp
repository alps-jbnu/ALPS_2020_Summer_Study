#include <stack>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int flag = 0;
	while (true) {
		stack<char>stack;
		char c[101];
		cin.getline(c,101);
		if (c[0] == '.') {
			break;
		}
		for(int i=0;c[i]!='.';i++) {
			switch (c[i])
			{
				case '(':
					if (stack.empty() == true || stack.top() == '('|| stack.top() == '[') {
						stack.push('(');
					}
					else {
						flag++;
					}
					break;
				case ')':
					if (stack.empty() == true || stack.top()=='['|| stack.top() == ']'|| stack.top() == ')') {
						flag++;
					}
					else if (stack.top() == '(') {
						stack.pop();
					}
					break;
				case '[':
					if (stack.empty() == true || stack.top() == '(' || stack.top() == '[') {
						stack.push('[');
					}
					else {
						flag++;
					}
					break;
				case ']':
					if (stack.empty() == true || stack.top() == '(' || stack.top() == ']' || stack.top() == ')') {
						flag++;
					}
					else if (stack.top() == '[') {
						stack.pop();
					}
					break;
			}
		}
		if (stack.empty() == true && flag == 0) {
			cout << "yes"<<endl;
		}
		else {
			cout << "no"<<endl;
		}
		flag = 0;
	}

	return 0;
}