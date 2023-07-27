#include <bits/stdc++.h>

using namespace std;

// 정의 : dp[i][j] -> i번 집까지 칠하는 비용의 최솟값, 현재 j로 칠해짐(0,1,2)
// 점화식 :dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r[i]
//       dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + r[i]
//       dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + r[i]
// 초깃값 : dp[1][1], dp[1][2], dp[1][0] = 비용

int dp[1005][5];
int arr[1005][5];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for(int i=1; i<=n; i++){
    for(int j=0; j<3; j++){
      cin >> arr[i][j];
    }
  }

  for(int i=1; i<=n; i++){
      dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
      dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
      dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + arr[i][2];
  }

  int mn = min(dp[n][0],dp[n][1]);
  cout << min(mn,dp[n][2]);
}