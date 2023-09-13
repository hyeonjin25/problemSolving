#include <bits/stdc++.h>

using namespace std;

// 50*50
long long arr[60];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  long long newscore,p; cin >> newscore >> p;

  for(int i=0; i<n; i++) cin >> arr[i];

  if(n==0) {cout << 1; return 0;}

  if(p==n&&arr[n-1]>=newscore) {cout << -1; return 0;}

  for(int i=n-1; i>=0; i--){
    if(arr[i]>newscore) {
      cout << i+2;
      return 0;
    }
  }

  cout << 1;

}