#include <bits/stdc++.h>
using namespace std;

long long arr[95];

long long func(int k){
  if(k==0) return 0;
  if(k==1) return 1;
  if (arr[k] != 0) return arr[k];
  return arr[k] = func(k-1) + func(k-2);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin>>n;
  cout << func(n);
}