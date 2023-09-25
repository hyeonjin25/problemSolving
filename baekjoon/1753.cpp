#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> mat[20010];
int d[20010];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int v,e,a; cin >> v>>e>>a;

  int u,vv,w;
  for(int i=0; i<e; i++){
    cin >> u>>vv>>w;
    mat[u].push_back({w,vv});
  }

  fill(d,d+v+1,1e9);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  d[a]=0;
  pq.push({d[a],a});

  while(pq.size()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.second]!=cur.first) continue;
    for(auto nxt:mat[cur.second]){
      if(d[nxt.second]<=d[cur.second]+nxt.first) continue;
      d[nxt.second]=d[cur.second]+nxt.first;
      pq.push({d[nxt.second],nxt.second});
    }
  }
  for(int i=1; i<=v; i++){
    if(d[i]==1e9) cout << "INF\n";
    else cout << d[i] << '\n';
  }
}