#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  string name, stat;

  set<string> s;

  for(int i=0; i<n; i++){
    cin >> name >> stat;
    if(stat=="enter") s.insert(name);
    else if(stat=="leave") s.erase(name);
  }
  
  vector<string> v(s.begin(), s.end());
  sort(v.rbegin(), v.rend());

  for(string e:v){
    cout << e << '\n';
  }
}