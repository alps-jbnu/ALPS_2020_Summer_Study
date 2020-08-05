#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> A;
	for (int i = 0, num; i < 9; i++) {
		cin >> num;
		A.push_back(num);
	}
	int first, second;
	vector<int> ans;
	first = 0;
	while (first < A.size()) {
		second = first + 1;
		while (second < A.size()) {
			int sum = 0;
			for (int i = 0; i < 9; i++) {
				if(i != first && i != second)
					sum += A[i];
			}
			if (sum == 100) {
				for (int i = 0; i < 9; i++) {
					if (i != first && i != second)
						ans.push_back(A[i]);
				}
				break;
			}
			second += 1;
		}
		if (!ans.empty())
			break;
		first += 1;
	}
	sort(ans.begin(), ans.end());
	for (int a : ans)
		cout << a << endl;
}