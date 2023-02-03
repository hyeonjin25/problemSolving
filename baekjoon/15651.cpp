#include <bits/stdc++.h>

using namespace std;

int n,m;
int isused[10];
int arr[10];

void func(int k){
  if(k==m){
    for(int i=0;i<m;i++)
      cout << arr[i] << ' ';
     cout << '\n';
    return;
  }

  for(int i=1;i<n+1;i++){
        isused[i]=1;
        arr[k]=i;
        func(k+1);
        isused[i]=0;
      
    }
}


int main(){
  ios::sync_with_stdio(); cin.tie(0);

  cin >> n>>m;
  func(0);
}