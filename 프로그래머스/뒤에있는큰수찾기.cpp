#include <string>
#include <vector>

using namespace std;

// 시간초과 풀이

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();
    
    for(int i=0; i<n; i++){
        int cur = numbers[i];
        int flag=0;
        for(int j=i+1; j<n; j++){
            if(cur<numbers[j]) {
                answer.push_back(numbers[j]); 
                flag=1;
                break;
            }
        }
        if(!flag) answer.push_back(-1);
    }
    return answer;
}