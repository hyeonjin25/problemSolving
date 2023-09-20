#include<bits/stdc++.h>
using namespace std;

// 1000000

int mat[110][110];
int MX = 10000001;
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m; cin >>n>>m;
  int a,b,c;
  for(int i=1; i<=n;i++){
    fill(mat[i],mat[i]+n+1,MX);
  }
  for(int i=0;i<m; i++){
    cin >> a >> b>>c;
    mat[a][b]=min(mat[a][b],c);
  }

  for(int i=1; i<=n; i++) mat[i][i] = 0;

  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){ 
        mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
      }
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1;j<=n; j++){
      if(mat[i][j]==MX) cout << 0 << ' ';
      else cout << mat[i][j] << ' ';
    }
    cout << '\n';
  }
}