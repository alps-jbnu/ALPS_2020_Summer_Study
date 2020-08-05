#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(vector<vector<int>> baseball) {
	vector<string> A;
	for (char i = '1'; i <= '9'; i++) {
		for (char j = '1'; j <= '9'; j++) {
			for (char k = '1'; k <= '9'; k++) {
				if (i != j && j != k && k != i) {
					string str({ i, j, k });
					A.push_back(str);
				}
			}
		}
	}

	for (int j = 0; j < baseball.size(); j++) {
		vector<int> command = baseball[j];
		string key = to_string(command[0]);
		int s = command[1], b = command[2];

		for (int i = 0; i < A.size(); i++) {
			if (A[i] == "-1") continue;
			int strike = 0, ball = 0;
			for (int a = 0; a < 3; a++) {
				for (int b = 0; b < 3; b++) {
					if (a == b && key[a] == A[i][b]) strike++;
					else if (key[a] == A[i][b]) ball++;
				}
			}
			if (strike != s || ball != b) {
				A[i] = "-1";
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] != "-1") ans++;
	}

	return ans;
}

int main() {
	vector<vector<int>> A;
	A.resize(1);

	for (int i = 0; i < A.size(); i++) {
		int num, s, b;
		cin >> num >> s >> b;
		A[i].push_back(num);
		A[i].push_back(s);
		A[i].push_back(b);
	}
	cout << solution(A) << endl;
}