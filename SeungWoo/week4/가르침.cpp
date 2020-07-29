#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, k, ans;
string word[51];
bool alp[26];

void solve(int now, int kl) {
	if (kl == k) {
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			bool check = true;
			for (int j = 0; j < word[i].length(); j++) {
				if (!alp[word[i][j] - 'a']) {
					check = false;
					break;
				}
			}
			if (check) tmp++;
		}
		ans = max(ans, tmp);
	}

	for (int i = now; i < 26; i++) {
		if (!alp[i]) {
			alp[i] = true;
			solve(i,kl + 1);
			alp[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> word[i];
		word[i] = word[i].substr(4, word[i].length());
		for (int j = 0; j < 4; j++) word[i].pop_back();
	}
	if (k < 5) cout << 0;
	else if (k == 26) cout << n;
	else {
		k -= 5;
		alp['a' - 'a'] = true;
		alp['n' - 'a'] = true;
		alp['t' - 'a'] = true;
		alp['i' - 'a'] = true;
		alp['c' - 'a'] = true;

		solve(0, 0);
		cout << ans;
	}
	return 0;
}