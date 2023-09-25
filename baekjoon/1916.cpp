#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> mat[1005];
int d[1005];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m; cin >>n>>m; 
  int a,b,c;
  for(int i=0; i<m; i++){
    cin >>a>>b>>c;
    mat[a].push_back({c,b});
  }
  int st,ed; cin >>st>>ed;

  fill(d,d+n+1,1e9);
  d[st]=0;
  priority_queue<pair<int,int>>pq;
  pq.push({0,st});

  while(pq.size()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.second]!=cur.first) continue;
    for(auto nxt:mat[cur.second]){
      if(d[nxt.second]<=d[cur.second]+nxt.first) continue;
      d[nxt.second]=d[cur.second]+nxt.first;
      pq.push({d[nxt.second],nxt.second});
    }
  }
  cout << d[ed] << '\n';
}