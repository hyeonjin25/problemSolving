#include<bits/stdc++.h>
using namespace std;

// 정의 : dp[i] = i번째 타일을 채울 때 방법의 수
// 점화식 : dp[i] = dp[i-1] + dp[i-2]*2
// 초깃값 : dp[1] = 1, dp[2] = 3

int dp[1005];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  dp[1] = 1, dp[2] = 3;

  for(int i=3; i<=n; i++){
    dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
  }
  
  cout << dp[n];
}