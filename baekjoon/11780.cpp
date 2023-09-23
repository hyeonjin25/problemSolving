#include<bits/stdc++.h>
using namespace std;

int mat[110][110];
int pre[110][110];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m; cin >> n>>m;

  for(int i=1; i<=n; i++) fill(mat[i],mat[i]+n+1,100005);

  int a,b,c;
  while(m--){
    cin >> a>>b>>c;
    mat[a][b]=min(mat[a][b],c);
    pre[a][b]=b;
  }

  for(int i=1; i<=n; i++) mat[i][i]=0;

  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(mat[i][j]>mat[i][k]+mat[k][j]){
          mat[i][j]=mat[i][k]+mat[k][j];
          pre[i][j] = pre[i][k];
        }
      }
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(mat[i][j]==100005) mat[i][j]=0;
      cout << mat[i][j] <<' ';
    }
    cout << '\n';
  }


  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      vector<int>ans;
      if(mat[i][j]==0) { cout << 0 << '\n'; continue;}
      int cur = i;
      while(1){
        ans.push_back(cur);
        
        cur = pre[cur][j];
        if(cur==j) break;
      }
      ans.push_back(j);
      cout << ans.size() << ' ';
      for(int i=0; i<ans.size(); i++){
        cout << ans[i] << ' ';
      }
      cout << '\n';
    }
  }
}