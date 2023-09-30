#include<bits/stdc++.h>
using namespace std;

vector <pair<int,int>> mat[1005];
priority_queue<pair<int,int>> q;
int d[1005];
int pre[1005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m; cin >> n>>m;
  for(int i=0; i<m; i++){
    int a,b,c;
    cin >>a>>b>>c;
    mat[a].push_back({c,b});
  }
  
  int st,ed; cin >> st>>ed;
  fill(d,d+n+1,1e9);

  q.push({0,st});
  d[st]=0;
  pre[st]=0;

  while(q.size()){
    auto cur = q.top(); q.pop();
    if(d[cur.second]!=cur.first) continue;
    for(auto nxt:mat[cur.second]){
      if(d[nxt.second]<=d[cur.second]+nxt.first)continue;
      d[nxt.second]=d[cur.second]+nxt.first;
      q.push({d[nxt.second],nxt.second});
      pre[nxt.second]=cur.second;
    }
  }
  cout << d[ed] << '\n';

  stack<int>s;
  int cnt=1;
  int now = ed;
  s.push(ed);
  while(1){
    if(now==st) break;
    now = pre[now];
    s.push(now);
    cnt++;
  }
  cout << cnt <<'\n';

  while(s.size()){
    cout << s.top() << ' ';
    s.pop();
  }
}