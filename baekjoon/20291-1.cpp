#include <bits/stdc++.h>

using namespace std;

map<string,int> m;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  string str;
  for(int i=0; i<n;i++){
    cin >> str;
    int idx = str.find('.');
    m[str.substr(idx+1)]++;
  }

  for(auto e:m) cout << e.first << ' ' << e.second << '\n';
}