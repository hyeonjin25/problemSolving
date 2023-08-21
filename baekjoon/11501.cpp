#include<bits/stdc++.h>
using namespace std;

int arr[1000005];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
#if TEST
    freopen("/Users/shj41/programming/problemSolving/input.txt", "r", stdin);
#endif

  int T; cin >> T;
  
  while(T--){
    int n; cin >> n;

    for(int i=0; i<n; i++){
      cin >> arr[i];
    }

    int mx=0;
    long long sum=0;
    for(int i=n-1; i>=0; i--){
      int cur = arr[i];
      if(mx>cur) sum+=mx-cur;
      else mx = cur;
    }

    cout << sum << '\n';
  }
  
}