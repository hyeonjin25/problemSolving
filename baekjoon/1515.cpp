#include <bits/stdc++.h>

using namespace std;

int dir[3030];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  
  string s; cin >> s;

  long long num=1;
  string stn;
  for(int i=0; i<s.size(); i++){
    char cur = s[i];
    
    while(1){
      if(stn.size()==0) stn=to_string(num++);
      for(int j=0; j<stn.size(); j++){
        char scur=stn[0];
        stn = stn.substr(1);
        if(scur==cur) goto g;
      }
    }
    g: continue;
  }
  
  cout << num-1;
}