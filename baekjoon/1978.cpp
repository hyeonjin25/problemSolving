#include <bits/stdc++.h>

using namespace std;


int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >>n;

  int c, flag;
  int cnt=n;
  while(n--){
    cin >> c; 
    if(c==1) cnt--;

    for(int i=2; i<=sqrt(c); i++){
      if(c%i==0) {
        cnt--; break;
      }
    }
  }
  cout << cnt;
}