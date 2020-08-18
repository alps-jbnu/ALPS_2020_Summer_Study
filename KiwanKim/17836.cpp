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

int N,M,T;
int castle[105][105];
bool visited[105][105][2];//[N][M][검의 유무]
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

struct status{
    int x;
    int y;
    bool sword;//검을 소지했는지 안 했는지
};
int bfs(){
    int ret = INF;//(N,M)에 도착했을 때, 최소시간 출력
    int steps = 0;//이동시간에 해당

    queue<status> q;//주로 사용하는 큐
    queue<status> q2;//스왑을 위한 큐(중간에 q가 다 사용되면 다음것이 저장된 q2와 교환)

    status stat,cur_stat;//stat은 q에 들어갈 다음칸의 정보들, cur_stat은 현재 칸의 정보
    stat.x = stat.y = 1;//
    stat.sword = false;//처음엔 칼을 안 가지고 있다.
    q.push(stat);
    visited[1][1][0] = true;//처음 칸으 방문 표시

    int tx,ty;
    int x,y;
    bool cur_sword;//현재 칼을 소지했는가

    while(!q.empty()){
        steps++;//1시간 증가
        while(!q.empty()){
            cur_stat = q.front();
            q.pop();
            //현재 칸의 정보를 저장
            x = cur_stat.x; y = cur_stat.y; cur_sword = cur_stat.sword;

            for(int i=0;i<4;i++){
                tx = x + dx[i];
                ty = y + dy[i];
                stat.x = tx; stat.y = ty; stat.sword = cur_sword;//큐에 넣을 다음칸의 정보 stat
                if(tx<=0 || ty<=0 || tx>N || ty>M)
                    continue;
                if(!cur_sword && castle[tx][ty] == 1)//현재 칼X, 다음칸에 벽과 조우
                    continue;


                if(castle[tx][ty]==2)//다음칸에 칼이 있으면 q2에 넣을 stat을 조정
                    stat.sword = true;

                if(visited[tx][ty][stat.sword])//이미 다음칸을 방문했을 경우
                    continue;

                visited[tx][ty][stat.sword] = true;
                if(tx== N && ty == M)//공주님을 만났을 경우
                    ret = min(ret,steps);
                else{
                    q2.push(stat);//q2에 저장하는 이유는..
                }                 //현재 while문의 q는 steps만큼 이동했을 때 도달한 칸들인데
            }                     //다음칸 즉 steps+1만큼 이동한 칸들은 q가 아닌 q2에 임시로 넣어줍니다.
        }

        swap(q,q2);//비어있는 q와 다음 것이 들어있는 q2 스왑
    }
    
    return ret;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> T;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> castle[i][j];
        }
    }

    int sec = bfs();
    if(sec<=T)
        cout << sec;
    else
        cout << "Fail";

    return 0;
}
