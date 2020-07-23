#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	if (arr[0] > 1) cout << 1;
	else {
		int sum = 1;

		for (int i = 1; i < n; i++) {
			if (arr[i] > sum+1) break;
			sum += arr[i];
		}

		cout << sum + 1;
	}

	return 0;
}
