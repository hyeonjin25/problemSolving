#include <bits/stdc++.h>

using namespace std;

int arr[105];
int n,k; 

int dp(int a){
  if(a<0) return 0;

  dp(0) = 0;
  dp(a) = 0;
  for(int i=0; i<n; i++){
    dp(a)+=dp(a-i);
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >>k;
  
  for(int i=0;i<n;i++){
    cin >>  arr[i];
  }
}