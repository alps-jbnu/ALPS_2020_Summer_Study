#include<iostream>
#include<cstring>
using namespace std;

bool check[50][50]; // 배추 유무
bool chk[50][50];   // 방문 여부
int n, w[50], h[50], cnt[50], coun[50];


void tmp(int x, int y) {
	if (chk[x][y] == true) return;
	else {
		chk[x][y] = true;
		if (y != 0 && chk[x][y - 1] == false && check[x][y - 1] == true) tmp(x, y - 1);
		if (x != 0 && chk[x - 1][y] == false && check[x-1][y] == true) tmp(x - 1, y);
		if (y < 49 && chk[x][y + 1] == false && check[x][y + 1] == true) tmp(x, y + 1);
		if (x < 49 && chk[x + 1][y] == false && check[x + 1][y] == true) tmp(x + 1, y);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i] >> w[i] >> cnt[i];
		for (int j = 0; j < cnt[i]; j++) {
			cin >> a >> b;
			check[a][b] = true;
		}
		for (int x = 0; x < h[i]; x++) 
			for (int y = 0; y < w[i]; y++) 
				if (chk[x][y] == false && check[x][y] == true) {
					coun[i]++;
					tmp(x, y);
				}
		for (int l = 0; l < 50; l++) {
			for (int k = 0; k < 50; k++) {
				check[l][k] = false;
				chk[l][k] = false;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << coun[i] << "\n";

	return 0;
}
