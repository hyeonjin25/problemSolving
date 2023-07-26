#include<bits/stdc++.h>
using namespace std;

// 정의 : dp[i][j] -> i번째 계단을 밟았을 때의 점수의 최댓값, j개의 계단을 연속해서 밟은 상태
// 점화식 : dp[i][1] = max(dp[i-2][1],dp[i-2][2]) + s[i]
//        dp[i][2] = dp[i-1][1] + s[i]
// 초깃값 : dp[1][1] = s[1], dp[1][2] = 0, dp[2][1] = s[2]

int dp[305][305];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  int s[305];
  for(int i=1; i<=n; i++){
    cin >> s[i];
  }

  dp[1][1] = s[1], dp[1][2] = 0, dp[2][1] = s[2];
  for(int i=2; i<=n; i++){
    dp[i][1] = max(dp[i-2][1],dp[i-2][2]) + s[i];
    dp[i][2] = dp[i-1][1] + s[i];
  }

  cout << max(dp[n][1],dp[n][2]);
}