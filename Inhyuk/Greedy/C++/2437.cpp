#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	long long sum = 1;
	if (A[0] == 1) {
		for (int i = 1; i < A.size(); i++) {
			if (A[i] > sum + 1) 
				break;
			sum += A[i];
		}
		cout << sum + 1<< endl;
	}
	else {
		cout << sum << endl;
	}
}