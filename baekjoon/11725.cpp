#include<bits/stdc++.h>

using namespace std;

int par[100005];

int main(){
  int n; cin >>n;
  vector<int> v[100005];
  queue<int> q;

  int a,b;
  for(int i=0; i<n-1; i++){
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  q.push(1);
  while(q.size()){
    auto cur = q.front(); q.pop();
    for(auto a:v[cur]){
      if(par[cur]==a) continue;
      q.push(a);
      par[a]=cur;
    }
  }

  for(int i=2; i<=n; i++){
    cout << par[i] << '\n';
  }
}