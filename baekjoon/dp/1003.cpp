#include<bits/stdc++.h>

using namespace std;

// 정의 : dp[i][0] : fibonacci(i)일 때 0의 출력 횟수
//       dp[i][1] : fibonacci(i)일 때 1의 출력 횟수
// 점화식 : dp[i][0] = dp[i-1][0] + dp[i-2][0]
//        dp[i][1] = dp[i-1][1] + dp[i-2][1]

int dp[45][5];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);


  dp[0][0] = 1, dp[1][1] = 1;

  for(int i=2; i<=40; i++){
    dp[i][0] = dp[i-1][0] + dp[i-2][0];
    dp[i][1] = dp[i-1][1] + dp[i-2][1];
  }

  int n; cin >> n;
  int a;
  for(int i=0;i<n;i++){
    cin >> a;
    cout << dp[a][0] << ' ' << dp[a][1] << '\n'; 
  }
}
