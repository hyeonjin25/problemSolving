#include<iostream>
using namespace std;

char mat[202][202];
char temp[202][202];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int r,c,n; cin >> r>>c >>n;
  
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin >> mat[i][j];
    }
  }

  if(n%2==0){
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        cout << 'O'; 
      } 
      cout << '\n';
    }
    return 0;
  }


  for(int k=2; k<n; k+=2){
    for(int i=0; i<r; i++){
      fill(temp[i],temp[i]+c,'O');
    }

    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        if(mat[i][j]=='O'){
          temp[i][j]='.';
          for(int k=0; k<4; k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx<0||ny<0||nx>=r||ny>=c) continue;
            temp[nx][ny] = '.';
          }
        }
      }
    }

    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        mat[i][j] = temp[i][j];
      }
    }
  }

  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cout << mat[i][j]; 
    }
    cout << '\n'; 
  }
}