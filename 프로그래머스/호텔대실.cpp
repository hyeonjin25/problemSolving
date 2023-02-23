#include <bits/stdc++.h>
#include <vector>

using namespace std;

int cmp(const vector<string>& a, const vector<string>& b){
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]<b[0];
}

int toInt(const string& s){
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3));
    return (h-1)*60 + m;
}

int solution(vector<vector<string>> book_time) {
    int n=book_time.size();
    vector<string> v;
    
    sort(book_time.begin(),book_time.end(),cmp);
    
    v.push_back(book_time[0][1]);
    int flag=0;
    for(int i=1; i<n;i++){
        for(auto &e:v){
            if(toInt(e)+10<=toInt(book_time[i][0])) {
                e=book_time[i][1];
                flag=1;
                break;
            }
        }
        if(!flag) v.push_back(book_time[i][1]);
        flag=0;
    }
    
    return v.size();
}