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

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
string Map[55];
int cnt[55][55][65]; // [N][M][2^6(A~F)]
void dfs(int x,int y,int count,int keys){
    if(Map[x][y]=='1'){
        return;
    }

    int tx,ty;//다음 이동 좌표를 나타냅니다.
    for(int i=0;i<4;i++){
        tx = x + dx[i];
        ty = y + dy[i];

        if(tx<0 || ty<0 || tx >= N || ty >= M || Map[tx][ty] == '#')
            continue;//범위를 초과하거나 벽이면 다른 이동점을 살펴봅니다.
        if('a' <= Map[tx][ty] && Map[tx][ty] <= 'f'){//열쇠를 포함한 칸이면
            int addKeys = keys | (1<<(Map[tx][ty]-'a'));//해당 열쇠를 갖고
            if(cnt[tx][ty][addKeys] > count+1){//해당 열쇠들을 갖은 경우의 기존 count와 비교
                cnt[tx][ty][addKeys] = count+1;//만약 현재 위치가 더 적은 칸수를 이동했다면
                dfs(tx,ty,count+1,addKeys);//업데이트하고 이칸에 대해서 dfs를 재귀적으로 돌려줍니다.
            }
        }else if('A' <= Map[tx][ty] && Map[tx][ty] <= 'F'){//만약 벽을 만났을 경우
            if((keys & (1<<(Map[tx][ty]-'A')))==0)//하지만 가지고 있는 열쇠중에 문을 열 수 있는 것이 없다면
                continue;//넘어갑니다.
            else if(cnt[tx][ty][keys] > count+1){//반면 열쇠를 갖고 있고 현재 이동수가 더 적다면
                cnt[tx][ty][keys] = count+1;//업데이트하고
                dfs(tx,ty,count+1,keys);//이에대해서 dfs를 들어갑니다.
            }
        }else if(Map[tx][ty]=='.' || Map[tx][ty] == '1'){//문이 아니거나 열쇠도 아니면
            if(cnt[tx][ty][keys] > count + 1){//만약 현재 이동수가 더 적다면
                cnt[tx][ty][keys] = count+1;//업데이트하고
                dfs(tx,ty,count+1,keys);//이에 대해서 dfs를 들어갑니다.
            }
        }
    }
}
void init(){
    for(int i=0;i<55;i++){
        for(int j=0;j<55;j++){
            for(int k=0;k<65;k++){
                cnt[i][j][k] = INF;
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    init();//모든 cnt배열을 INF(큰값)으로 초기화
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> Map[i];
    }

    int sx,sy;
    //시작점 즉 '0'인 곳을 찾습니다.
    bool flag = false;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Map[i][j] == '0'){
                flag = true;
                sx = i;
                sy = j;
                Map[i][j] = '.';
                break;
            }
        }
        if(flag)
            break;
    }

    cnt[sx][sy][0] = 0;//'0'인 점은 아직 안 움직였으니까 0으로 초기화
    dfs(sx,sy,0,0);

    int ans = INF;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Map[i][j] == '1'){//'1'이면 해당 점을 방문한 count수를 모든 경우의 수를 확인
                for(int k=0;k<65;k++){//모든 경우의 수를 확인
                    ans = min(ans,cnt[i][j][k]);
                }
            }
        }
    }
    if(ans==INF)//만약 '1'을 방문하지 못했을 경우
        cout << -1;
    else
        cout << ans;
    return 0;
}
