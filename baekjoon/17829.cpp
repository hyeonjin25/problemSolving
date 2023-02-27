#include<bits/stdc++.h>
using namespace std;

int m[1030][1030];

int func(int x, int y, int n){
  int a,b,c,d;
  if(n==2) {
    a = m[x][y];
    b = m[x+1][y];
    c = m[x][y+1];
    d = m[x+1][y+1];
  }
  else {
    n = n/2;
    a = func(x,y,n);
    b = func(x+n,y,n);
    c = func(x,y+n,n);
    d = func(x+n,y+n,n);
  }

  int arr[4] = {a,b,c,d};
  sort(arr, arr+4);
  return arr[2];
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> m[i][j];
    }
  }

  cout << func(0,0,n);
}