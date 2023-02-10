#include <bits/stdc++.h>

using namespace std;

int n;
char mat[405][405];

void func(int nn,int x,int y){
  if(nn-1==n) return;
  int len=(nn-1)*5-(nn-2);
  for(int i=0; i<len; i++){
    mat[x+i-len/2][y]='*';
    mat[x+i-len/2][y+len-1]='*';
    mat[x+len/2][y+i]='*';
    mat[x-len/2][y+i]='*';
  }
  func(nn+1,x,y-2);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;

  for(int i=0;i<405;i++){
    fill(mat[i],mat[i]+405,' ');
  }

  int len=(n-1)*5-(n-2);
  func(1,len/2,len/2);

  for(int i=0; i<=len; i++){
    for(int j=0; j<=len; j++){
      cout << mat[i][j];
    }
    cout << '\n';
  }
}