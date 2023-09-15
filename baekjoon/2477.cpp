#include <bits/stdc++.h>

using namespace std;

int sz[10];
int dir[10];
int func(int st,int go){
  return sz[(st+go)%6];
}


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  
  int k; cin >> k;
  for(int i=0; i<6; i++) cin >> dir[i] >> sz[i];
  int big=1, sm=1;
  for(int i=0; i<6; i++){
    if(sz[i]==func(i,2)+func(i,4)) {
      big*=sz[i];
      sm*=func(i,3);
    }
  }

  cout << (big-sm)*k;
}
