#include <bits/stdc++.h>

using namespace std;

int mat[1005][1005];
int n, st, m;
int a,b;

void func(int x, int y){
  int len=n-x*2;
  if(len==1) {
    mat[x][y]=1;
    return;
  }
  for(int i=0; i<len; i++) {
    if(st==m){a=x+i; b=y;} 
    mat[x+i][y]=st--;
  }
  for(int i=0; i<len-2; i++) {
    if(st==m){a=x+len-1; b=y+1+i;} 
    mat[x+len-1][y+1+i]=st--;
  }
  for(int i=0; i<len; i++) {
    if(st==m){a=x+len-1-i; b=y+len-1;} 
    mat[x+len-1-i][y+len-1]=st--;
  }
  for(int i=0; i<len-2; i++) {
    if(st==m){a=x; b=y+len-2-i;};
    mat[x][y+len-2-i]=st--;
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

  st = n*n;
  for(int i=0; i<(n+1)/2; i++){
    func(i,i);
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << mat[i][j] << ' ';
    }
    cout << '\n';
  }

  if(m==1) cout << (n+1)/2 << ' ' << (n+1)/2 ;
  else cout << a+1 << ' ' << b+1;
}