#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>>mat[100005];
queue<int>q;
int vis[100005];

void bfs(int st){
  fill(vis,vis+100005,-1);

  q.push(st); vis[st]=0;


  while(q.size()){
    int cur = q.front(); q.pop();
    for(int i=0; i<mat[cur].size(); i++){
      int chil = mat[cur][i].first;
      int val = mat[cur][i].second;
      if(vis[chil]>-1) continue;
      q.push(chil);
      vis[chil]=vis[cur]+val;
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  int a,b,c;
  for(int i=0; i<n-1; i++){
    cin >> a>>b>>c;  
    mat[a].push_back({b,c});
    mat[b].push_back({a,c});
  }

  bfs(1);

  int mx=0;
  int gl=0;
  for(int i=1; i<=n; i++){
    if(vis[i]>mx){
      mx = vis[i];
      gl = i;
    }
  }

  bfs(gl);

  mx=0;
  for(int i=1; i<=n; i++){
    mx = max(mx,vis[i]);
  }

  cout << mx;
}