#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
using namespace std;
 
#define INF 987654321
#define INF2 1e9;
#define MOD 998244353
#define pii pair<int,int>
#define pll pair<long long,long long>
typedef long long ll;
typedef unsigned long long ull;

int N,M;
vector<int> jewels;
int calc(int x){//x개만큼 나누준다고 할때 총 나누어 줄 수 있는 학생수를 리턴
    int ret = 0;
    for(int i=0;i<jewels.size();i++){
        ret += jewels[i]/x;
        if(jewels[i]%x)//x보다 작은 갯수가 남으면 학생1명에게 나누어 줄 수 있다고 생각한다.
            ret++;
    }
    return ret;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int tmp;
    int maxi = 0;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> tmp;
        maxi = max(maxi,tmp);//최대 보석갯수를 구합니다.
        jewels.push_back(tmp);
    }

    int low,high,mid;
    low=1;
    high=maxi;
    //이분탐색을 사용시
    //함수를 사용할 수 도 있고
    //아래와 같이 while문으로 간단하게 사용할 수 도 있습니다.
    while(low<high){
        mid = (low+high)/2;
        if(calc(mid) <= N){//mid를 기준으로 보석을 나누어주었을때
            high = mid;    //총 나누어 줄 수 있는 학생수가 N보다 작거나 같다면 더 작은 단위로 나누어 주어야합니다.
        }else{          //총 나누어 줄 수 있는 학생수가 N보다 크다면 더 큰 단위로 나누어 주어야 합니다.
            low = mid+1;
        }
    }

    cout << low;//while문의 탈출조건이 low<high 이므로 low>=high 이므로 low 혹은 high를 출력해줍니다.

    return 0;
}
