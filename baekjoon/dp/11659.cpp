#include<bits/stdc++.h>

using namespace std;

// 정의 : dp[i] -> 1 부터 i까지의 합
// 점화식 : i~j까지의 합 = dp[j] - dp[i-1]
// 초깃값 : dp[0] = 0

int dp[100005];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m;
  cin >> n >>m;

  for(int i=1; i<=n; i++){
    cin >> dp[i];
    dp[i]= dp[i]+dp[i-1];
  }

  int a,b;
  for(int t=0; t<m; t++){
    cin >> a >> b;

    cout << dp[b] - dp[a-1] << '\n';
  }
}