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
int T,M,N,K,X,Y;
int baechu[55][55];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int y,int x){
    queue<pii> q;
    q.push({y,x});
    int tx,ty;
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            ty = y + dy[i];
            tx = x + dx[i];

            if(ty<0 || tx<0 || ty>=N || tx>=M || baechu[ty][tx]==0)
                continue;
            baechu[ty][tx] = 0;
            q.push({ty,tx});
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        for(int i=0;i<K;i++){
            cin >> X >> Y;
            baechu[Y][X] = 1;
        }

        int cnt = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(baechu[i][j]){
                    cnt++;
                    baechu[i][j] = 0;
                    bfs(i,j);
                }
            }
        }
        cout << cnt << '\n';
        memset(baechu,0,sizeof(baechu));
    }

    return 0;
}
