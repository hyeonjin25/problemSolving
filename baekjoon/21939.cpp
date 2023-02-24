#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  multimap<int,int> mp;

  int n; cin >> n;
  for(int i=0;i<n; i++) {
    int a,b; cin >> a >>b;
    mp.insert({b,a});
  }

  int m; cin >>m;
  for(int i=0;i<m; i++){
    string str;
    if(str=="recommend"){
      int a; cin >> a;
      if(a==1) cout << mp.rbegin()->second<< '\n';
      else cout << mp.begin()->second << '\n';
    }else if(str=="add"){
      int a,b; cin >> a>>b;
      mp.insert({b,a});
    }else if(str=="solved"){
      int a; cin >> a;
      //mp.erase(find)
    }
  }
}