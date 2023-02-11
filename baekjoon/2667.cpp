#include <bits/stdc++.h>

using namespace std;

string mat[30];
int vis[30][30];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

queue<pair<int,int>>Q;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  for(int i=0;i<n;i++) 
      cin >> mat[i];

  int tot=0; 
  int num=0;
  vector<int>numA;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++){
      if(mat[i][j]=='1'&&vis[i][j]==0){
        Q.push({i,j}); vis[i][j]=1; num=1; tot++;
        while(Q.size()){
          auto cur = Q.front(); Q.pop();
          for(int k=0; k<4;k++){
            int nx= cur.first+dx[k];
            int ny= cur.second+dy[k];
            if(nx<0||ny<0||nx>=n||ny>=n) continue;
            if(vis[nx][ny]==1||mat[nx][ny]=='0') continue;
            Q.push({nx,ny});
            vis[nx][ny]=1;
            num++;
          }
        }
        numA.push_back(num);
      }
    }
  }

  sort(numA.begin(), numA.end());

  cout << tot << '\n';
  for(int i:numA) cout << i << '\n';
}
