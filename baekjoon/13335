#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vec;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n,leng,weigh;
    int front=0;
    int res=0;
    cin >> n >> leng >> weigh;
    
    int temp;
    for(int i=0; i<n;i++){
        cin >> temp;
        vec.push_back({temp,0});
    }
    
    while(1){
        if(front>=n) break;
        
        int sum=0;
        for(int i=front;i<front+leng;i++){
            if(i>=n) break;
            sum+=vec[i].first;
            if(sum>weigh) break;
            vec[i].second+=1;
        }
        
        if(vec[front].second>=leng) {
            front++;
        }
        
        res++;
    }
    
    cout << res + 1; // 맨 앞이 들어가는 시간 더해줌
}