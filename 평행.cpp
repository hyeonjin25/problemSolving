#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    int per[4]={0,0,1,1};

    do{
        vector<vector<int>> a,b;
        for(int i=0; i<4;i++){
            if(per[i]==0) a.push_back(dots[i]);
            else b.push_back(dots[i]);
        }
        if(abs(a[0][0]-a[1][0])*abs(b[0][1]-b[1][1]) == abs(a[0][1]-a[1][1])*abs(b[0][0]-b[1][0])) answer=1;
    }while(next_permutation(per,per+4));
    
    return answer;
}
