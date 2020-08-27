#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string com(string a, string b) {
	string rst(max(a.size(),b.size()),'0');
	bool check = false;
	
	for(int i=0;i<rst.size();i++) {
		int tmp = check;
		check = false;
		
		if(i<a.size()) tmp+=a[a.size()-i-1] - '0';
		if(i<b.size()) tmp+=b[b.size()-i-1] - '0';
		if(tmp>=10) {
			check = true;
			tmp-=10;
		}
		rst[rst.size()-i-1] = tmp+'0';
	}
	if(check) rst.insert(rst.begin(),'1');
	return rst;
}

int main() {
	int n;
	cin>>n;
	string f = "0", s = "1";
	if(n==0) cout<<f;
	else if(n==1) cout<<s;
	else {
		string ans;
		for(int i=0;i<=n-2;i++) {
			ans = com(f,s);
			f = s;
			s = ans;
		}
		
		cout<<ans;
	}
	return 0;
}
