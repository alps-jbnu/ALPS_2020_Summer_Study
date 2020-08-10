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
int Map[305][305];
bool visited[305][305];
int melt_cnt[305][305];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x,int y){
    int tx, ty;

    for(int i=0;i<4;i++){
        tx = x + dx[i];
        ty = y + dy[i];

        if(tx<0 || ty<0 || tx >= N || ty>= M || visited[tx][ty])
            continue;

        if(Map[tx][ty]==0){
            melt_cnt[x][y]--;
        }else{
            visited[tx][ty] = true;
            dfs(tx,ty);
        }
    }
}

void apply_melt(){
    for(int i=1;i<N-1;i++){
        for(int j=1;j<M-1;j++){
            Map[i][j] += melt_cnt[i][j];
            if(Map[i][j]<0)
                Map[i][j] = 0;
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> Map[i][j];
        }
    }

    int year = 0;
    bool flag = false;
    while(true){
        memset(visited,false,sizeof(visited));
        memset(melt_cnt,0,sizeof(melt_cnt));
        int cnt = 0;
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(Map[i][j] != 0 && !visited[i][j]){
                    cnt++;
                    visited[i][j] = true;
                    dfs(i,j);
                }
            }
        }

        if(cnt>=2){
            flag = true;
            break;
        }else if(cnt==0)
            break;

        year++;

        apply_melt();
    }

    if(flag)
        cout << year;
    else
        cout << 0;
    return 0;
}
