#include <bits/stdc++.h>

using namespace std;

int arr[1005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for(int i=0; i<n; i++) cin >>arr[i];

  sort(arr,arr+n);

  int res=0;
  int sum=0;
  for(int i=0;i<n;i++) {
    sum+=arr[i];
    res+=sum;
  }
  
  cout << res;
}