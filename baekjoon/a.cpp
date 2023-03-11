#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m,k;
  cin >> n>>m>>k;

  int t = k;
  int ans=0;

  while(t>1){
    t/=2;
    ans++;
  }

  int cnt=0;
  t=n;
  while(t>1){
    t/=2;
    cnt++;
  }
  cnt-=ans;

  if(cnt<m) ans+=cnt;
  else ans+=m;

  cout << ans; 
}