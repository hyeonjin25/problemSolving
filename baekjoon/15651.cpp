#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[10];

void func(int k){
  if(k==m){
    for(int i=0;i<m;i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i=1;i<n+1;i++){
        arr[k]=i;
        func(k+1);
    }
}


int main(){
  ios::sync_with_stdio(); cin.tie(0);

  cin >> n>>m;
  func(0);
}