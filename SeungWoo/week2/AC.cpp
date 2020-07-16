#include<iostream>
#include<string>
using namespace std;

int ar[100001];

void solve(string sik, int le) {
	int now = 0;
	int all = le;
	bool reverse = false;

	for (int i = 0; i < sik.length(); i++) {
		if (sik[i] == 'R') {
			if (reverse == false) reverse = true;
			else reverse = false;
		}
		else if (sik[i] == 'D') {
			if (!reverse) {
				if (now < all) now++;
				else {
					cout << "error\n";
					return;
				}
			}
			else {
				if (now < all) all--;
				else {
					cout << "error\n";
					return;
				}

			}
		}
	}
	if (now == all) {
		cout << "[]\n";
	}
	else {
		cout << '[';
		if (!reverse) {
			for (int i = now; i < all; i++) {
				if (i == all - 1) cout << ar[i] << "]\n";
				else cout << ar[i] << ',';
			}
		}
		else {
			for (int i = all - 1; i >= now; i--) {
				if (i == now) cout << ar[i] << "]\n";
				else cout << ar[i] << ',';
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string sik,arr;
	int n,m, k, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		k = 0;
		cin >> sik >> m >> arr;

		for (int j = 0; j < m; j++) ar[j] = 0;

		if (m != 0) {
			for (int j = 0; j < arr.length(); j++) {
				if (arr[j] >= '0' && arr[j] <= '9') {
					num = 0;
					while (1) {
						num = num * 10 + arr[j] - '0';
						if (arr[j + 1] > '9' || arr[j + 1] < '0' || j + 1 == arr.length()) break;
						j++;
					}
					ar[k++] = num;
				}
			}
		}
		solve(sik, m);
	}
}
