#include<bits/stdc++.h>
using namespace std;

int a[55],b[55];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  for(int i=0; i<n; i++) cin >>a[i];
  for(int i=0; i<n; i++) cin >>b[i];

  sort(a,a+n);
  sort(b,b+n,greater<>());

  int s = 0;
  for(int i=0; i<n; i++){
    s+=(a[i]*b[i]);
  }

  cout << s;
}
