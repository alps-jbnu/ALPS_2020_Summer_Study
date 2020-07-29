#include <string>
#include <vector>
#include <iostream>

using namespace std;
int ans1[] = {1,2,3,4,5};
int ans2[] = {2,1,2,3,2,4,2,5};
int ans3[] = {3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt[4];
    cnt[1] = cnt[2] = cnt[3] = 0;
    for(int i=0;i<answers.size();i++){
        if(answers[i] == ans1[i%5])
            cnt[1]++;
        if(answers[i] == ans2[i%8])
            cnt[2]++;
        if(answers[i] == ans3[i%10])
            cnt[3]++;
    }
    int max=0;
    for(int i=1;i<=3;i++){
        if(cnt[i]>max){
            max = cnt[i];
            answer.clear();
            answer.push_back(i);
        }else if(cnt[i]==max){
            answer.push_back(i);
        }
    }


    return answer;
}

