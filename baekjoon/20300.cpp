#include <bits/stdc++.h>

using namespace std;

long long t[10005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  for(int i=0; i<n; i++) cin >> t[i];

  sort(t,t+n);

  long long big=0;
  if(n%2==1) {
    big = t[n-1];
    n--;
  }

  for(int i=0; i<n/2;i++){
    big = max(big, t[i]+t[n-i-1]);
  }

  cout << big;
}