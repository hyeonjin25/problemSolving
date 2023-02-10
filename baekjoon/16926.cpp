#include <bits/stdc++.h>
using namespace std;

int n,m,r;
int arr[305][305];

void func(int x, int y, int x2, int y2){
  int temp=arr[x][y];

  for(int i=y; i<y2; i++) arr[x][i] = arr[x][i+1];
  for(int i=x; i<x2; i++) arr[i][y2] = arr[i+1][y2];
  for(int i=y2; i>y; i--) arr[x2][i] = arr[x2][i-1];
  for(int i=x2; i>x; i--) arr[i][y] = arr[i-1][y];
  
  arr[x+1][y]=temp;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m >>r;

  int temp;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> arr[i][j];  

  while(r--){
    for(int i=0; i<(min(n,m)/2);i++) 
      func(i,i,n-1-i,m-1-i);
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
}