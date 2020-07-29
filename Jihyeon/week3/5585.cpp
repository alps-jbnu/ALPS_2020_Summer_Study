#include <iostream>
using namespace std;
int main() {
	int m;
	int charge;
	int c500, c100, c50, c10, c5, c1;
	cin >> m;
	charge = 1000 - m;
	c500 = charge / 500;
	charge %= 500;
	c100 = charge / 100;
	charge %= 100;
	c50 = charge / 50;
	charge %= 50;
	c10 = charge / 10;
	charge %= 10;
	c5 = charge / 5;
	charge %= 5;
	c1 = charge / 1;
	charge %= 1;
	cout << c500 + c100 + c50 + c10 + c5 + c1;
	return 0;
}