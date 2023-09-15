#include <bits/stdc++.h>

using namespace std;

// 50*50
long long arr[60]; 

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  long long news, p; cin >> news >> p;

  for(int i=1; i<=n; i++) cin >> arr[i];
  
  int cnt=0;
  for(int i=1; i<=n; i++){
    if(arr[i]>news) cnt++;
  }
  
  if(n==p&&arr[n]>=news) cout << -1;
  else cout << cnt+1;
}