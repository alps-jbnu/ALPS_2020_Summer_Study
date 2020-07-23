#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int A[] = { 500, 100, 50, 10, 5, 1 };
	N = 1000 - N;
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (N < A[i]) continue;
		cnt += N / A[i];
		N %= A[i];
		if (N == 0) break;
	}
	cout << cnt << endl;
}