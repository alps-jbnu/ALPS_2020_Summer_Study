#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int l, p, v;

	for(int i=1;i>0;i++) {
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) break;
		else {
			int result = 0;
			result += l * (v / p);
			v = v % p;
			result += min(l, v);
			cout << "Case " << i << ": " << result << "\n";
		}
	}
	return 0;
}
