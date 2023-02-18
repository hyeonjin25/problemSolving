#include <bits/stdc++.h>

using namespace std;

int arr[100005];

bool cmp(int a, int b){
  return a>b;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];

  sort(arr, arr+n, cmp);

  long long sum=0;
  for(int i=0; i<n; i++){
    if(arr[i]-i>0) sum+=(arr[i]-i);
  }

  cout << sum;
}