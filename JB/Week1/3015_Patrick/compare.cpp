// code by KiWan
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
#define INF 987654321
#define INF2 1e9;
#define MOD 998244353
#define pii pair<int, int>
#define pll pair<long long, long long>
typedef long long ll;
int N;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    stack<pll> st;
    ll f, s; //f는 키, s는 나와 키가 같은 사람의 수
    ll ans = 0;
    while (N--)
    {
        cin >> f;
        s = 1; // 나와 키가 같은 사람은 나 1명이다.
        if (st.empty())
        { //지금 아무도 줄 서 있지 않다면 그냥 push
            st.push({f, s});
        }
        else
        {
            while (true)
            { //스택에는 지금까지 내앞에 줄을 서있는 사람이 들어있습니다.
                //이때 내가 해당 스택에 들어가고자 하는데
                //나 보다 키가 작은 사람이 이미 내 앞에 있으면
                //나로 인해 그 키가 작은 사람은 내 뒤에 오게 될 사람과 짝을 짓지 못하게 됩니다.
                //그래서 현재 스택에 나보다 키가 큰 사람이 있으면 그 사람과 나를 짝을 짓고
                //나보다 키가 작은 사람들은 스택에서 pop합니다.
                if (st.empty())
                { //그러다가 나보다 키가 작은 사람이 더이상 내앞에 없으면 나를 push
                    st.push({f, s});
                    break;
                }
                else if (st.top().first <= f)
                { //해당사람이 나보다 키가 작거나 같으면
                    pll tmp = st.top();
                    st.pop();          // 그사람을 빼줍니다.
                    ans += tmp.second; // 이때 second는 중복된 연속된 사람의 수를 의미 합니다.
                    //그러니 222224와 같다고 할때 내앞에 똑같은 2가 5개가 있는 꼴인데 전부 4랑 짝을지을수 있으니
                    //ans += 5를 해주는 것과 같습니다.
                    if (tmp.first == f)
                    {                    // 근데 만약 나와 키가 같다면
                        s += tmp.second; //현재 내가 만난 나와 키가 같은 사람의 수를 s에 더해줍니다. 다음차례에 나는 스택에 들어 갈 것입니다.
                    }
                }
                else if (st.top().first > f)
                {                    //만약 나보다 키가 큰사람이 스택에 있다면
                    st.push({f, s}); //나는 그냥 넣어줍니다. 왜냐하면 키큰 사람보다 앞에 있는 사람과 나는 짝을 지을 수 없기 때문입니다.
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}