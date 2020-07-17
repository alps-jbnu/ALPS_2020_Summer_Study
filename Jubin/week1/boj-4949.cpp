#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

enum
{
	SIZE = 102
};

int main()
{
	char sentence[SIZE];
		
	while (fgets(sentence, SIZE, stdin) != NULL)
	{
		int len = strlen(sentence);
		
		if (*sentence == '.')
		{
			break;
		}
		
		bool ok = true;
		stack<int> st;
		
		for (int i = 0; i < len; ++i)
		{
			char c = sentence[i];
			
			if (st.empty())
			{
				if (c == ')' || c == ']')
				{
					ok = false;
					break;
				}
			}
			
			if (c == '(' || c == '[')
			{
				st.push(c);
			}
			else if (c == ')')
			{
				if (st.top() == '(')
				{
					st.pop();
					continue;
				}
				
				ok = false;
				break;
			}
			else if (c == ']')
			{
				if (st.top() == '[')
				{
					st.pop();
					continue;
				}
				
				ok = false;
				break;
			}
		}
		
		ok = ok && st.empty();
		
		puts(ok ? "yes" : "no");
	}
	
	return 0;
}
