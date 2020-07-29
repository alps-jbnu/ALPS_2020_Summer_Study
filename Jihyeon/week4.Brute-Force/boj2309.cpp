#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int cnt = 0;
	vector<int>h = vector<int>();
	vector<int>idx = vector<int>();
	vector<int>real = vector<int>();
	for (int i = 0; i < 9; i++) {
		int n;
		cin >> n;

 		h.push_back(n);
	}
	int k = 7;
	for (int i = 0; i < k; i++) {
		idx.push_back(1);
	}
	for (int i = 0; i < h.size() - k; i++) {
		idx.push_back(0);
	}
	sort(idx.begin(), idx.end());
	/*for (int i = 0; i < 5; i++) {
		idx.push_back(1);
	}
	idx.push_back(0);
	idx.push_back(0); 
	idx.push_back(1); 
	idx.push_back(1);*/
	do {
		for (int i = 0; i < idx.size(); i++) {
			if (idx[i] == 1) {
				cnt += h[i];
				real.push_back(h[i]);
			}
		}
		if (cnt == 100) {
			sort(real.begin(), real.end());
			for (int i = 0; i < 7; i++) {
				cout << real[i] << endl;
			}
			break;
		}
		else {
			cnt = 0;
			real.clear();
		}
	} while (next_permutation(idx.begin(), idx.end()));
	
	
	return 0;
}