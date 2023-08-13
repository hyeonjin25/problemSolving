#include<bits/stdc++.h>
using namespace std;

// 정의 : dp[i][j] -> 1~i번째 자리수이고, i번째 자리가 j일때 계단수의 개수
// 점화식 : dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
// 초깃값 : dp[1][0] = 0, dp[1][1] = 1 ,...

long long dp[105][15];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
#if TEST
    freopen("/Users/shj41/programming/problemSolving/input.txt", "r", stdin);
#endif

  int n; cin >> n;

  dp[1][0] = 0;
  for(int i=1; i<=9; i++) dp[1][i] = 1;

  for(int i=2; i<=n; i++){
    for(int j=0; j<=9; j++){
      if(j==0) dp[i][j] = dp[i-1][j+1] % 1000000000;
      else if(j==9) dp[i][j] = dp[i-1][j-1] % 1000000000;
      else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
    }
  }
  
  long long sum = 0;
  for(int i=0; i<=9; i++) sum+=dp[n][i] % 1000000000;

  cout << sum % 1000000000;
}