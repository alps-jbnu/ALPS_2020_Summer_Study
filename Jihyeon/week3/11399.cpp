#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	int cnt = 0;
	int sum = 0;
	cin >> N;
	vector<int>vec;
	for (int i = 0; i < N; i++) {
		int s;
		cin >> s;
		vec.push_back(s);
	}
	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cnt += vec[j];
		}
		sum += cnt;
		cnt = 0;
	}
	cout << sum;
	return 0;
}