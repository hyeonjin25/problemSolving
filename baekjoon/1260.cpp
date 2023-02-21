#include <bits/stdc++.h>

using namespace std;

vector<int> vec[1005];
int vis1[1005];
int vis2[1005];
queue<int> q;
stack<int> s;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,st; cin >> n >> m >> st;
  
  for(int i=0; i<m;i++){
    int a,b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  for (int i=1; i<=n; i++) {
    sort(vec[i].rbegin(), vec[i].rend());
  }

  // dfs
  s.push(st);
  while(s.size()){
    int cur = s.top();
    s.pop();
    if(vis1[cur]) continue;
    vis1[cur]=1;
    cout << cur << ' ';
    for(auto a: vec[cur]){
      if(vis1[a]) continue;
      s.push(a);
    }
  }
  cout << '\n';

  for (int i=1; i<=n; i++) {
    sort(vec[i].begin(), vec[i].end());
  }

  // bfs
  q.push(st);
  vis2[st]=1;
  //cout << st << ' ';
  while(q.size()){
    int cur = q.front();
    q.pop();
    cout << cur << ' ';
    for(auto a: vec[cur]){
      if(vis2[a]) continue;
      q.push(a);
      vis2[a]=1;
    }
  }
}