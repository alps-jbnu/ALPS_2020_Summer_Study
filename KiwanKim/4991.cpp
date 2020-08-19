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

int w,h;

int room[25][25];
int trash_cnt = 0;
int cnt[25][25][1<<10];//총10개의 쓰래기가 있습니다.
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

struct status{//큐에 넣어줄 좌표와 현재까지 치운 쓰레기의 번호 기록
    int x;
    int y;
    int trash;
};

int bfs(int sx,int sy){
    int ret = INF;
    queue<status> q;//주로 사용할 큐
    queue<status> q2;//새롭게 추가 될 것들을 담을 큐
    status stat;
    int x,y,trash;
    stat.x = sx;
    stat.y = sy;
    stat.trash = 0;
    cnt[sx][sy][0] = 0;

    q.push(stat);//'o'의 좌표 및 치운 쓰레기수 0을 큐에 삽입

    int steps = 0;
    int tx,ty;

    while(!q.empty()){

        steps++;//이동한 칸의 수 증가
        while(!q.empty()){//현재 큐에 담겨져 있는것만 본다. 각칸에 의해 생기는 새로운 칸들은 q2에 넣어준다.
            auto front = q.front();
            q.pop();
            x = front.x; y = front.y; trash = front.trash;

            for(int i=0;i<4;i++){
                trash=front.trash;//4개의 칸을 검사중에 모두 똑같은 변수를 사용하므로 front.trash로 계속 초기화
                tx = x + dx[i];
                ty = y + dy[i];

                if(tx<0 || ty<0 || tx>=h || ty>=w || room[tx][ty]==-1)//범위초과 및 벽을 만났을때
                    continue;

                if(room[tx][ty]>0)//쓰레기를 만났을때
                    trash = trash | (1<<(room[tx][ty]-1));//현재가지고 있는 쓰레기에 추가

                if(trash==((1<<trash_cnt)-1)){//모든 쓰레기를 모았을때
                    ret = min(ret,steps);//리턴값을 업데이트
                }
                else if(cnt[tx][ty][trash] > steps){//아직 모든 쓰레기를 치우지 못하고 다음칸보다 적은 이동수를 가졌을 때
                    cnt[tx][ty][trash] = steps;
                    stat.x = tx; stat.y = ty; stat.trash=trash;
                    q2.push(stat);//임시로 넣어주는 q2
                }
            }
        }
        swap(q,q2);//여기서 스왑
    }
    return ret;
}
void init(){
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++){
            for(int k=0;k<(1<<10);k++){
                cnt[i][j][k] = INF;
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        init();//매 경우 마다 공통된 cnt를 사용하기에 초기화
        trash_cnt=0;//쓰레기의 번호
        cin >> w >> h;
        if(w==0 && h==0)
            break;

        int sx,sy;
        
        string tmp;
        for(int i=0;i<h;i++){
            cin >> tmp;
            for(int j=0;j<tmp.length();j++){
                if(tmp[j]=='.')
                    room[i][j] = 0;
                else if(tmp[j] == 'o'){
                    room[i][j] = 0;
                    sx = i; sy = j;
                }else if(tmp[j] == '*'){//쓰레기를 만났을때, 쓰레기 번호를 부여
                    room[i][j] = ++trash_cnt;
                }else if(tmp[j] == 'x'){//벽은 -1
                    room[i][j] = -1;
                }
            }
        }

        int ans = bfs(sx,sy);
        if(ans==INF)
            cout << -1 << '\n';
        else
            cout << ans << '\n';

    }

    return 0;
}
