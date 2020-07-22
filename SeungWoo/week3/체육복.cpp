#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int arr[31];
    
    for(int i=1;i<=n;i++) arr[i] = 1;
    
    for(int i=0;i<lost.size();i++)
        arr[lost[i]]--;
    
    for(int i=0;i<reserve.size();i++)
        arr[reserve[i]]++;
    
    for(int i=1;i<=n;i++) {
        if(i==1) {
            if(arr[i]==2 && arr[i+1]==0) {
                arr[i]=1;
                arr[i+1]=1;
            }
        }
        else if(i==n) {
            if(arr[i]==2 && arr[i-1]==0) {
                arr[i]=1;
                arr[i-1]=1;
            }
        }
        else {
            if(arr[i]==2) {
                if(arr[i-1]==0) {
                    arr[i]=1;
                    arr[i-1]=1;
                }
                if(arr[i+1]==0) {
                    if(arr[i]==2) {
                        arr[i]=1;
                        arr[i+1]=1;
                    }
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++) 
        if(arr[i]>0) answer++;
    return answer;
}
