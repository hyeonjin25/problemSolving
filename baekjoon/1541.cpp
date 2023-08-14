#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  
  string str; cin >> str;

  int res = 0;
  int num = 0;
  bool calc = 0; // 0 = +, 1 = -
  for(char c: str){
    if(c=='-'||c=='+') {
      if(calc) res -= num;
      else res += num;
      num=0;
      if(c=='-') calc = 1;
      continue;
    }
    num = num*10 + int(c-'0');
  }

  if(calc) res -= num;
  else res += num;
  cout << res;
}