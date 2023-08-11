#include<bits/stdc++.h>

using namespace std;

long long dp[105];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int T; cin >> T;

  dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;

  for(int i = 5; i<=100; i++){
    dp[i] = dp[i-5] + dp[i-1];
  }

  while(T--){
    int n; cin >> n;

    cout << dp[n] << '\n';
  }
}