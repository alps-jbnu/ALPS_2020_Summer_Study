#include <bits/stdc++.h>
using namespace std;
int N;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool visit[51][51];
string board[51];

bool isAvailable(int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= N)
        return false;
    return true;
}

int calcVer(int x, int y, char ch) {
    if(!isAvailable(x, y) || visit[y][x] || ch != board[y][x]) return 0;
    visit[y][x] = true;
    int ret = calcVer(x, y + 1, board[y][x]);
    ret += calcVer(x, y - 1, board[y][x]);
    visit[y][x] = false;
    return ret + 1;
}

int calcHor(int x, int y, char ch) {
    if(!isAvailable(x, y) || visit[y][x] || ch != board[y][x]) return 0;
    visit[y][x] = true;
    int ret = calcHor(x + 1, y, board[y][x]);
    ret += calcHor(x - 1, y, board[y][x]);
    visit[y][x] = false;
    return ret + 1;
}

int main() {
    cin >> N;
    int i = 0, ans = 0;
    while(i < N)
        cin >> board[i++];
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            for(int idx = 0; idx < 4; idx++) {
                int nx = x + dx[idx];
                int ny = y + dy[idx];
                if(isAvailable(nx, ny)) {
                    swap(board[y][x], board[ny][nx]);
                    ans = max(ans, calcVer(x, y, board[y][x]));
                    // cout << "x , y :" << x << " " << y << "nx, ny : " << nx << " " << ny << " " << calcVer(x, y, board[y][x]) << "\n";
                    ans = max(ans, calcHor(x, y, board[y][x]));
                    // cout << "x , y :" << x << " " << y << "nx, ny : " << nx << " " << ny << " " << calcHor(x, y, board[y][x]) << "\n";
                    swap(board[y][x], board[ny][nx]);
                }
            }
        }
    }
    cout << ans;
}