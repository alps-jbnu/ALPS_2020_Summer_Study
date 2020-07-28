#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;
int N,M;
int map[501][501];
bool visited[501][501];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int func(int x,int y,int cur){
    if(cur==3) return map[x][y];
    int maxi=-1;
    int tx,ty;
    for(int i=0;i<4;i++){
        tx = x + dx[i];
        ty = y + dy[i];
        if(tx<0 || tx>=N || ty<0 || ty>=M || visited[tx][ty]==true) continue;
        visited[tx][ty]=true;
        int tmp = func(x+dx[i],y+dy[i],cur+1);
        if(tmp>maxi) maxi = tmp;
        visited[tx][ty]=false;
    }
    return map[x][y]+maxi;
}
int func2(int x,int y){
    int maxi=-1;
    if(x-1>=0 && x+1<N && y-1>=0)
        maxi=max(maxi,map[x-1][y-1]+map[x][y-1]+map[x+1][y-1]);
    if(x-1>=0 && y-1>=0 && y+1<M)
        maxi=max(maxi,map[x-1][y-1]+map[x-1][y]+map[x-1][y+1]);
    if(x-1>=0 && x+1<N && y+1<M)
        maxi=max(maxi,map[x-1][y+1]+map[x][y+1]+map[x+1][y+1]);
    if(x+1<N && y-1>=0 && y+1<M)
        maxi=max(maxi,map[x+1][y-1]+map[x+1][y]+map[x+1][y+1]);
    return maxi+map[x][y];
}

int main(){
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    int ans = -1;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visited[i][j]=true;
            int tmp = func(i,j,0);
            visited[i][j]=false;
            int tmp2 = func2(i,j);
            ans = max(ans,max(tmp,tmp2));
        }
    }
    cout << ans;

}
