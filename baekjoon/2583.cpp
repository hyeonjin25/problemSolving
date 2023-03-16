#include<bits/stdc++.h>

using namespace std;

int paper[105][105];
int vis[105][105];
queue<pair<int,int>>q;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
  int m,n,k; cin >> m>>n>>k;

  while(k--){
    int a,b,c,d;
    cin >>a >> b>>c>>d;
    for(int i=0; i<d-b; i++){
      for(int j=0; j<c-a; j++){
        paper[m-b-1-i][a+j] = 1;
      }
    }
  }

  int cnt=0;
  vector<int> size;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(paper[i][j]==1||vis[i][j]==1) continue;
      q.push({i,j}); vis[i][j]=1;
      cnt++;
      int s=1;
      while(q.size()){
        auto cur = q.front(); q.pop();
        for(int k=0; k<4; k++){
          int nx = cur.first + dx[k];
          int ny = cur.second + dy[k];
          if(nx<0||ny<0||nx>=m||ny>=n) continue;
          if(vis[nx][ny]==1||paper[nx][ny]==1) continue;
          s++;
          q.push({nx,ny});
          vis[nx][ny]=1;
        }
      }
      size.push_back(s);
    }
  }

  cout << cnt << '\n';
  sort(size.begin(), size.end());
  for(auto a:size){
    cout << a << ' ';
  }
  
}