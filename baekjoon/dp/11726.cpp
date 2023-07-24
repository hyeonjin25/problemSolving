#include<bits/stdc++.h>

using namespace std;

// 정의 : dp[i] -> 2*i 크기 직사각형 채우는 방법의 수
// 초깃값 : dp[1] -> 1, dp[2] -> 2
// 점화식 : dp[i] = dp[i-1] + dp[i-2]

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  int dp[1005];
  dp[1] = 1, dp[2] = 2;

  for(int i=3; i<=n; i++){
    dp[i] = (dp[i-1] + dp[i-2])%10007;
  }

  cout << dp[n];
}