#include<bits/stdc++.h>

using namespace std;

long long arr[1005];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  long long n, m; cin >> n>> m;

  for(int i=0; i<n; i++) cin >> arr[i];
  
  long long res = 0;
  for(int i=0; i<m; i++){
    sort(arr, arr+n);
    long long arr0 = arr[0];
    arr[0] = arr[0]+arr[1];
    arr[1] = arr0+arr[1];
  }

  for(int i=0; i<n; i++) res+=arr[i];

  cout << res;
}