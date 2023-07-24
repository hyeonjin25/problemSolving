#include <bits/stdc++.h>
using namespace std;

int n,m; 
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int vis[505][505];
int mp[505][505];

int recur(int x, int y, int cnt){
  if(cnt==4) return mp[x][y];

  int mx = 0;
  for(int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx<0||ny<0||nx>=n||ny>=m) continue;
    if(vis[nx][ny]==1) continue;
    vis[nx][ny] = 1;
    mx = max(mx,recur(nx,ny,cnt+1));
    vis[nx][ny] = 0;
  }
  return mp[x][y]+mx;
}

int ok(int x, int y){
  if(x<0||y<0||x>=n||y>=m) return 0;
  return 1;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n>> m;

  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> mp[i][j];

  int mx =0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      vis[i][j] = 1;
      mx=max(mx,recur(i,j,1));
      vis[i][j] = 0;

      if(ok(i-1,j-1)&&ok(i-1,j)&&ok(i-1,j+1))
        mx=max(mx,mp[i][j]+mp[i-1][j-1]+mp[i-1][j]+mp[i-1][j+1]);

      if(ok(i+1,j-1)&&ok(i+1,j)&&ok(i+1,j+1))
        mx=max(mx,mp[i][j]+mp[i+1][j-1]+mp[i+1][j]+mp[i+1][j+1]);

      if(ok(i-1,j-1)&&ok(i,j-1)&&ok(i+1,j-1))
        mx=max(mx,mp[i][j]+mp[i-1][j-1]+mp[i][j-1]+mp[i+1][j-1]);

      if(ok(i-1,j+1)&&ok(i,j+1)&&ok(i+1,j+1))
        mx=max(mx,mp[i][j]+mp[i-1][j+1]+mp[i][j+1]+mp[i+1][j+1]);
    }
  }
  cout << mx;
}
