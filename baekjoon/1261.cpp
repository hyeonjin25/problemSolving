#include <bits/stdc++.h>
using namespace std;

bool vis[105][105][10005];
int maze[105][105];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

queue<tuple<int,int,int>>q;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m; cin >>m>>n; 
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      char cr;
      cin >> cr;
      maze[i][j] = cr-'0';
    }
  }

  q.push({0,0,0}); vis[0][0][0]=1;

  int ans = 1e9;
  while(q.size()){
    auto [a,b,c] = q.front(); q.pop();
    if(a==n-1 && b==m-1) ans=min(ans,c);

    for(int i=0; i<4; i++){
      int nx = a + dx[i];
      int ny = b + dy[i];
      int nc = c;
      if(nx<0||ny<0||nx>=n||ny>=m) continue;
      if(maze[nx][ny]==1) nc++;
      if(nc>n+m) continue;
      if(vis[nx][ny][nc]>0) continue;
      q.push({nx,ny,nc});
      vis[nx][ny][nc]=1;
    }
  }

  cout << ans;
}