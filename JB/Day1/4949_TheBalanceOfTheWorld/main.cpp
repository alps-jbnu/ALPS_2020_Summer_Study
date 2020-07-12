#include <bits/stdc++.h>
using namespace std;
stack<char> st;
string str;

int main() {
    while(1) {
        bool chk = false;
        getline(cin, str);
        //cout << str << "\n" << chk << '\n';
        if (str == ".")
            return 0;
        for (int i = 0; str[i]; i++)
        {
            char now = str[i];
            if (now == '(')
                st.push(')');
            else if (now == '[')
                st.push(']');
            else if (now == ')')
            {
                if (!st.empty() && st.top() == ')')
                    st.pop();
                else
                {
                    cout << "no\n";
                    chk = true;
                    break;
                }
            }
            else if (now == ']')
            {
                if (!st.empty() && st.top() == ']')
                    st.pop();
                else
                {
                    cout << "no\n";
                    chk = 1;
                    break;
                }
            }
        }
        if (!chk && st.empty())
            cout << "yes\n";
        else {
            if (chk == false)
                cout << "no\n";
            while(!st.empty()) st.pop();
        }
            
    }

}