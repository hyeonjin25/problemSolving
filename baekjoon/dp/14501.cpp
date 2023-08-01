#include<bits/stdc++.h>
using namespace std;

// 정의 : dp[i] -> i일에 상담을 시작했을 때 최대 수익
// 점화식 : dp[i] = max(dp[i+1], dp[i+t[i]]+p[i])
// 초깃값 : 

int dp[1500005];
int t[1500005];
int p[1500005];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for(int i=1; i<=n; i++){
    cin >> t[i] >> p[i];
  }

  for(int i=n; i>=1; i--){
    if(i+t[i]>n+1) dp[i] = dp[i+1];
    else {
      dp[i] = max(dp[i+1], dp[i+t[i]]+p[i]);
    }
  }

  cout << dp[1];
}