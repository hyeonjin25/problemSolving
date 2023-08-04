#include <bits/stdc++.h>
using namespace std;

int arr[505][505];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >>n;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=i; j++){
      cin >> arr[i][j];
    }
  }

  for(int i=n-1; i>0; i--){
    for(int j=1; j<=i; j++){
      arr[i][j] = arr[i][j] + max(arr[i+1][j], arr[i+1][j+1]);
    }
  }

  cout << arr[1][1];
}