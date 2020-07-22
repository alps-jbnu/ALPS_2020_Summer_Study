#include<iostream>
using namespace std;
int money;
int coin[] = { 500,100,50,10,5,1 };
int op() {
	int pay = 1000 - money;
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		while (pay - coin[i] >= 0) {
			pay -= coin[i];
			cnt++;
			if (pay == 0) 
				break;
		}
	}
	return cnt;
}
int main() {
	
	cin >> money;

	cout << op() << endl;

	
		return 0;
}