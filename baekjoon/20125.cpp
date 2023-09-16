#include <bits/stdc++.h>

using namespace std;

//1000*1000

string arr[1005];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;

  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  int hx=-1, hy;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j]=='*'){
        hx=i+1, hy=j;
        break;
      }
    }
    if(hx!=-1) break;
  }

  int lp,rp,bk,ld,rd;
  for(int i=hy-1; i>=0; i--){
    if(arr[hx][i]=='_') {
      lp = hy-i-1;
      break;
    }
    if(i==0) {
      lp = hy-i;
    }
  }
  for(int i=hy+1; i<=n; i++){
    if(arr[hx][i]=='_') {
      rp = i-hy-1;
      break;
    }
    if(i==n-1) {
      rp = i-hy;
    }
  }
  int bx;
  for(int i=hx+1; i<n; i++){
    if(arr[i][hy]=='_') {
      bk = i-hx-1;
      bx = i-1;
      break;
    }
  }

  for(int i=bx+1; i<=n; i++){
    if(arr[i][hy-1]=='_') {
      ld = i-bx-1;
      break;
    }
    if(i==n-1) {
      ld = i-bx;
    }
  }
  for(int i=bx+1; i<=n; i++){
    if(arr[i][hy+1]=='_') {
      rd = i-bx-1;
      break;
    }
    if(i==n-1) {
      rd = i-bx;
    }
  }

  cout << hx+1 << ' ' << hy+1 << '\n';
  cout << lp << ' ' << rp << ' ' << bk << ' ' << ld << ' ' << rd;
}