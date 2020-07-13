#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
priority_queue<int> left_pq;
priority_queue<int> right_pq;

int getMid(){
    if(left_pq.size() > right_pq.size())
        return left_pq.top();
    else if(left_pq.size() < right_pq.size())
        return right_pq.top();
    else
        return min(left_pq.top(),-right_pq.top());
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++){
        int tmp;
        cin >> tmp;
        if(left_pq.size() <= right_pq.size())
            left_pq.push(tmp);
        else
            right_pq.push(-tmp);

        //make balance
        if(i==1){
            cout << tmp << '\n';
        }else{
            int _left = left_pq.top();
            int _right = -right_pq.top();
            if(_left > _right){
                left_pq.pop();
                right_pq.pop();
                left_pq.push(_right);
                right_pq.push(-_left);
            }
            cout << getMid() << '\n';
        }

    }
    return 0;

}
