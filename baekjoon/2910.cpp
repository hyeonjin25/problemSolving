#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vec; // 개수, value

int cmp(const pair<int,int>& a, const pair<int,int>& b){
  return a.first > b.first;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n, c;
  cin >> n >> c;

  int temp;
  for(int i=0; i<n;i++){
    cin >> temp;
    
    bool flag=0;
    for(auto& a: vec){
      if(a.second==temp) {
        a.first++;
        flag=1;
        break;
      }
    }
    if(!flag) vec.push_back({1,temp});
  }

  stable_sort(vec.begin(), vec.end(), cmp);

  for(auto a:vec){
    while(a.first--) cout << a.second << ' ';
  }
}