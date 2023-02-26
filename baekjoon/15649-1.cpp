#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  int per[10];

  cin >>n>>m;

  for(int i=0; i<n;i++){
    if(i<m) per[i]=i+1;
    else per[i]=9;
  }

  do{
    int ans[10]{ 0 };
    for(int i=0; i<n;i++){
      ans[per[i]] = i+1;
    }
    for (int i=1; i<=m; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }while(next_permutation(per,per+n));
}