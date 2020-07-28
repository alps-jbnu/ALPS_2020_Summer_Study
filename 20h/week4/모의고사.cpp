#include <string>
#include <vector>

using namespace std;

int person[3];
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int first[5] = {1,2,3,4,5};
    int second[8] = {2,1,2,3,2,4,2,5};
    int third[10] = {3,3,1,1,2,2,4,4,5,5};
    for (int i=0; i<answers.size(); i++) {
        if(answers[i] == first[i%5])
            person[0]++;
        if(answers[i] == second[i%8])
            person[1]++;
        if(answers[i] == third[i%10])
            person[2]++;
    }
    int max_ele = 0;
    for (int i=0; i<3; i++) {
        max_ele = max(max_ele, person[i]);
    }

    for (int i=0; i<3; i++) {
        if(person[i] == max_ele)
            answer.push_back(i+1);
    }

    return answer;
}
