#include<bits/stdc++.h>
using namespace std;

int n,m,d; 
int mp[20][20];
int per[20];

int vis[20][20];
int Kill[20][20];

int dx[3]={0,-1,0};
int dy[3]={-1,0,1};

set<pair<int,int>> temp_Kill;

void bfs(int x, int y){  
  int cnt=0;
  queue<pair<int,int>> q;
  // visit 초기화
  for(int i=0; i<=n; i++) fill(vis[i],vis[i]+m,0);
  
  q.push({x,y});
  vis[x][y]=1;
  for(int k=0; k<d; k++){
    int sz = q.size();
    while (sz--) {
      auto cur = q.front(); q.pop();
      for(int i=0; i<3; i++){
        int nx = cur.first+dx[i];
        int ny = cur.second+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=m) continue;
        if(vis[nx][ny]==1) continue;
        if(mp[nx][ny]==1&&nx!=x&&Kill[nx][ny]==0){
          temp_Kill.insert({nx,ny});
          return;
        }
        vis[nx][ny]=1;
        q.push({nx,ny});
      }
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n>>m>>d;

  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin>> mp[i][j];

  for(int i=0; i<m; i++){
    if(i<3) per[i]=0;
    else per[i]=1;
  }

  int mx=0;

  do{
    int cnt=0;

    // 죽였던 적군 초기화
    for(int j=0; j<=n; j++) fill(Kill[j],Kill[j]+m,0);

    for(int i=0; i<n; i++){      
      for(int j=0; j<m; j++){
        if(per[j]==0) bfs(n-i,j); 
      } 
      cnt+=temp_Kill.size();
      for(auto e:temp_Kill){
        Kill[e.first][e.second]=1;
      }
      temp_Kill.clear();
    }
    mx = max(mx,cnt);
  }while(next_permutation(per,per+m));

  cout << mx;
}