#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    char state[32];
    
    memset(state, 1, sizeof(state));
    state[0] = state[31] = 0;
    
    for (int s : reserve)
    {
        ++state[s];
    }
    for (int s : lost)
    {
        --state[s];
    }
    
    for (int i = 1; i <= n; ++i)
    {
        if (state[i] == 0)
        {
            if (state[i - 1] > 1)
            {
                --state[i - 1];
                ++state[i];
            } else if (state[i + 1] > 1)
            {
                --state[i + 1];
                ++state[i];
            }
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        if (state[i] > 0)
        {
            ++answer;
        }
    }
    
    return answer;
}
