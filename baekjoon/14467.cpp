#include <bits/stdc++.h>

using namespace std;

vector<int> v[15];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for(int i=0; i<n; i++){
    int a,b;
    cin >> a>>b;
    v[a].push_back(b);
  }

  int cnt=0;
  for(int i=1; i<=10; i++){
    for(int j=1; j<v[i].size(); j++){
      if(v[i][j]!=v[i][j-1]) cnt++;
    }
  }

  cout << cnt;
}