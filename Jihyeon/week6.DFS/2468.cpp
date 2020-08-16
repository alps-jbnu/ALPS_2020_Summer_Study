#include <iostream>
using namespace std;
void dfs(int a, int b, int **w, int n);
int main() {
	int N;
	cin >> N;
	int max = 1;
	int *safe;
	int **region = new int*[N];
	int **water = new int*[N];
	int *ox=new int[N*N];
	int *oy = new int[N*N];
	int n = 0;
	int result = 0;

	for (int i = 0; i < N; i++) {
		region[i] = new int[N];
		for (int j = 0; j < N; j++) {
			int height;
			cin >> height;
			region[i][j] = height;
			if (max < height) {
				max = height;
			}
		}
	}
	safe = new int[max];
	for (int i = 0; i < max; i++) {
		safe[i] = 0;
	}
	for (int wh = 0; wh < max; wh++) // water height
	{
		n = 0;
		for (int i = 0; i < N; i++) {
			water[i] = new int[N];
			for (int j = 0; j < N; j++) {
				if (region[i][j] <= wh) {
					water[i][j] = -1;
				}
				else { // 안잠기는 곳 위치 저장
					water[i][j] = 1;
					ox[n] = i;
					oy[n] = j;
					n++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (water[ox[i]][oy[i]] == 1) {
				water[ox[i]][oy[i]] = 0;
				safe[wh]++;
				dfs(ox[i], oy[i], water,N);
			}
		}
	}
	for (int i = 0; i < max; i++) {
		if (result < safe[i]) {
			result = safe[i];
		}
	}
	cout << result;
	return 0;
}
void dfs(int a, int b, int **w,int n) {
	if (a - 1 >= 0) { // 좌
		if (w[a - 1][b] == 1) {
			w[a - 1][b] = 0;
			dfs(a - 1, b, w,n);
		}
	}
	if (a + 1 < n) { // 우
		if (w[a + 1][b] == 1) {
			w[a + 1][b] = 0;
			dfs(a + 1, b, w,n);
		}
	}
	if (b + 1 >= 0) { // 상
		if (w[a][b + 1] == 1) {
			w[a][b + 1] = 0;
			dfs(a, b + 1, w,n);

		}
	}
	if (b - 1 < n) { // 하
		if (w[a][b - 1] == 1) {
			w[a][b - 1] = 0;
			dfs(a, b - 1, w, n);

		}
	}
}