#include <bits/stdc++.h>
#include <vector>

using namespace std;

int toInt(const string& s){
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3));
    return (h-1)*60 + m;
}

int solution(vector<vector<string>> book_time) {
    int n=book_time.size();
    vector<pair<int,int>> v;
    
    for(auto e:book_time){
        v.push_back({toInt(e[0]), 1}); // 들어가는 이벤트
        v.push_back({toInt(e[1])+10, 0}); // 나가는 이벤트
    }
    
    sort(v.begin(),v.end());
    
    int cnt=0;
    int res=0;
    for(auto e:v){
        if(e.second==1) cnt++;
        else if(e.second==0) cnt--;
        res=max(res,cnt);
    }
    
    return res;
}