#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m; cin >> n>>m;
  string name;
  unordered_map<string,int> toI;
  string toS[100005];

  for(int i=1; i<=n; i++) {
    cin >> name;
    toI[name]=i;
    toS[i]=name;
  }

  for(int i=0; i<m; i++) {
    cin >> name;
    if(isdigit(name[0])) cout << toS[stoi(name)] <<'\n';
    else cout << toI[name] << '\n';
  }
}