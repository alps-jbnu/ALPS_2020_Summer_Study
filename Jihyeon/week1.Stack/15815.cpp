#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int>num;
string s;
int a, b;

int main() {

	cin>>s;
	//cout << s << endl;

	for(int i=0;s[i];i++){
		if (s[i] == '+' || s[i] == '-' || s[i] =='*' || s[i] =='/') {
			a = num.top();
			num.pop();
			b = num.top();
			num.pop();

			switch (s[i]) {
				case '+':
					num.push(a+b);
					break;
				case '-':
					num.push(b - a);
					break;
				case '*':
					num.push(a * b);
					break;
				case '/':
					num.push(b / a);
					break;
			}
		
		}
		else{
			num.push(s[i]-'0');
			//cout << s[i] << endl;
		}
	} 
	cout << num.top();
	return 0;
}

