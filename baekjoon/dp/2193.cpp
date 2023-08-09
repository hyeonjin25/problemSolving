#include<iostream>
using namespace std;

// 정의 : dp[i][j] -> i자리의 비트가 j일때 i자리 이친수의 개수
// 점화식 : 
// dp[i][0] = dp[i-1][0]+dp[i-1][1] + 1
// dp[i][1] = dp[i-1][0] + 1
// 초깃값 : dp[1][1] = 1, dp[1][0] = 0

long long dp[100][2];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >>n;

  dp[1][1] = 1, dp[1][0] = 0;

  for(int i=2; i<=n; i++){
    dp[i][0] = dp[i-1][0]+dp[i-1][1];
    dp[i][1] = dp[i-1][0];
  }

  cout << dp[n][0]+dp[n][1];
}