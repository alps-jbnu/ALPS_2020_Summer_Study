#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    stack<int> operand;
    cin >> str;
    for(int i = 0; str[i]; i++) {
        char input = str[i];
        if(input >= '0' && input <= '9')
            operand.push((int)input-'0');
        else {
            int a, b;
            if(input == '+') {
                a = operand.top();
                operand.pop();
                b = operand.top();
                operand.pop();
                operand.push(a+b);
            }
            else if(input == '-') {
                b = operand.top();
                operand.pop();
                a = operand.top();
                operand.pop();
                operand.push(a-b);
            }
            else if(input == '*') {
                b = operand.top();
                operand.pop();
                a = operand.top();
                operand.pop();
                operand.push(a * b);
            }
            else if(input == '/') {
                b = operand.top();
                operand.pop();
                a = operand.top();
                operand.pop();
                operand.push(a / b);
            }
        }
    }
    cout << operand.top();
}