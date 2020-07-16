#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

bool re(int a, int b)
{
	if(a > b) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c, s, cnt;
	int arr[101],arr2[101];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c >> s;
		cnt = 0;
		queue<int> q;
		queue<char> q2;
		for (int j = 0; j < c; j++) {
			if (j == s) q2.push('R');
			else q2.push('W');
			cin >> arr[j];
			arr2[j] = arr[j];
			q.push(arr[j]);
		}
		sort(arr2, arr2 + c, re);
		while (1) {
			int num = q.front();
			char ans = q2.front();
			if (num == arr2[cnt]) {
				cnt++;
				if (ans == 'R') break;
				q.pop();
				q2.pop();
			}
			else {
				q.pop();
				q.push(num);
				q2.pop();
				q2.push(ans);
			}
		}
		cout << cnt<<"\n";
	}
}
