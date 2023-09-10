#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  string str;
  cin >> str;

  string ans = "";

  int cnt=0;
  for(auto c: str){
    if(c=='.'){
      if(cnt%2!=0) {
        cout << -1;
        return 0;
      }
      int a = cnt/4;
      for(int i=0; i<a; i++){
        ans+= "AAAA";
      }
      if(cnt%4!=0){
        ans+= "BB";
      }
      ans+= '.';
      cnt = 0;
      continue;
    }
    cnt++;
  }

  if(cnt%2==1) {
    cout << -1;
    return 0;
  }
  int a = cnt/4;
  for(int i=0; i<a; i++){
    ans += "AAAA";
  }
  if(cnt%4!=0){
    ans += "BB";
  }

  cout << ans;
}