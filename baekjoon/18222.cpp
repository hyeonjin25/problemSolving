#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  long long k; cin >> k;

  int cnt=0;
  while(k!=1){
    long long n=1;
    while(k>n){
      n*=2;
    }
    k=k-n/2;
    cnt++;
  }
  cout << cnt%2;
}