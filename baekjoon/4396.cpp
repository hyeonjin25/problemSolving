#include <bits/stdc++.h>

using namespace std;

string mat[15];
string open[15];

char res[15][15];

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,1,-1,0,1,-1};

bool cmp(int a, int b){
  return a>b;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  for(int i=0; i<n; i++)cin >> mat[i];
  for(int i=0; i<n; i++)cin >> open[i];

  int bomb=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(open[i][j]=='.') continue;
      if(mat[i][j]=='*') bomb=1;
      int count=0;
      for(int k=0; k<8; k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx<0||ny<0||nx>=n||ny>=n) continue;
        if(mat[nx][ny]=='*') count++;
      }
      open[i][j]=count+'0';
      string s;
    }
  }


  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(bomb&&mat[i][j]=='*') cout << '*';
      else cout << open[i][j];
    }
    cout << '\n';
  }
}