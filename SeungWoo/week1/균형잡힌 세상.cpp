#include<iostream>
#include <stack>
#include<string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string word;
	while (getline(cin, word))
	{
		if (word.length() == 1 && word[0] == '.') break;
		bool check = true;
		stack<char> st;
		for (int i = 0; i < word.length(); i++) {
			if (word[i] == '[') st.push('[');
			else if (word[i] == '(') st.push('(');
			else if (word[i] == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else {
					check = false;
					break;
				}

			}
			else if (word[i] == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else {
					check = false;
					break;
				}
			}
		}
		if (check && st.empty()) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
