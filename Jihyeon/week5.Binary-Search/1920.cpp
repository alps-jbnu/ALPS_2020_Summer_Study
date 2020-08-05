#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	int N;
	int M;
	cin >> N;
	vector<int>arr1;
	for (int i = 0; i < N; i++) {
		int n1;
		cin >> n1;
		arr1.push_back(n1);
	}
	cin >> M;
	vector<int>arr2;
	for (int i = 0; i < M; i++) {
		int n2;
		cin >> n2;
		arr2.push_back(n2);
	}
	sort(arr1.begin(), arr1.end());
	
	for (int i = 0; i < M; i++)
	{
		int s = 0;
		int e = N - 1;
		int num = arr2[i];
		while (true) {
			int mid = (s + e) / 2;
			if (num == arr1[mid]) {
				cout << 1 <<"\n";
				break;
			}
			if (e - s == 1) {
				if (num == arr1[e]) {
					cout << 1<<"\n";
				}
				else {
					cout << 0<<"\n";
				}
				break;
			}
			if (num < arr1[mid]) {
				e = mid;
			}
			else if (num > arr1[mid]) {
				s = mid;
			}
		}
	}
	return 0;
}