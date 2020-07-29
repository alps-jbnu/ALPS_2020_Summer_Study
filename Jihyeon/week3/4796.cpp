#include <iostream>
using namespace std;
int main() {
	int L, P, V;
	int day=0;
	int c = 0;
	while (++c) {
		cin >> L >> P >> V;
		if (L == 0 & P == 0 & V == 0) {
			break;
		}
		day += V / P * L;
		if (V%P > L) {
			day += L;
		}
		else {
			day += V % P;
		}
		cout << "Case " << c << ": " << day << endl;
		day = 0;
	}
	return 0;
}