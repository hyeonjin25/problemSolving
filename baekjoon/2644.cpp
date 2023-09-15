#include <bits/stdc++.h>

using namespace std;

vector<int> mat[110];
queue<int> q;
int vis[110];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,a,b,m; cin >> n >> a >> b >> m;

  int x,y;
  for(int i=0; i<m; i++){
    cin>> x >> y;
    mat[x].push_back(y);
    mat[y].push_back(x);
  }

  q.push(a);
  vis[a]=1;
  while(q.size()){
    int cur=q.front(); q.pop();
    for(auto c:mat[cur]){
      if(vis[c]!=0) continue;
      q.push(c);
      vis[c]=vis[cur]+1;
      if(c==b){
        cout << vis[c]-1;
        return 0;
      }
    }
  }
  cout << -1;
}