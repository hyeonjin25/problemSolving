#include<bits/stdc++.h>
using namespace std;

pair<int,int> arr[400005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for(int i=0; i<n*2; i+=2) {
    cin >> arr[i].first >> arr[i+1].first;
    arr[i].second = 1;
    arr[i+1].second = 0;
  }

  sort(arr,arr+2*n);

  int sz = 0, mx = 0;

  for(int i=0; i<2*n; i++){
    if(arr[i].second) sz++;
    else sz--;
    mx = max(mx,sz);
  }

  cout << mx;
}