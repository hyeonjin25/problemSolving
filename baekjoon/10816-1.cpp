#include <bits/stdc++.h>

using namespace std;

int arr[500005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  for(int i=0; i<n;i++) cin >>arr[i];

  sort(arr, arr+n);

  int m; cin >>m;
  for(int i=0; i<m;i++){
    int a; cin >>a;
    cout<< upper_bound(arr,arr+n,a) -  lower_bound(arr,arr+n,a)<< ' ';
  }
}