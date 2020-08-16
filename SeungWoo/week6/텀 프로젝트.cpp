#include<iostream>
using namespace std;

int ans;
int arr[100001];
bool visit[100001];
bool done[100001];

void reset(int p) {
	for (int i = 1; i <= p; i++) {
		visit[i] = false;
		done[i] = false;
	}
}

void solve(int h) {
	visit[h] = true;

	int next = arr[h];

	if (!visit[next]) solve(next);
	else if (!done[next]) {
		for (int i = next; i != h; i = arr[i])
			ans++;
		ans++;
	}
	done[h] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p, num;
	cin >> n;
	for (int k = 0; k < n; k++) {
		ans = 0;
		cin >> p;
		reset(p);
		for (int i = 1; i <= p; i++)
			cin >> arr[i];

		for (int i = 1; i <= p; i++)
			if (!visit[i]) solve(i);

		cout << p-ans << "\n";
	}
}
