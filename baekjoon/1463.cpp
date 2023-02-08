#include <bits/stdc++.h>

using namespace std;

int dp[1000005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; 
  cin >> n;

  dp[1]=0;

  for(int i=2; i<=n; i++){
    dp[i]=dp[i-1]+1;
    if(i%3==0) dp[i]=min(dp[i/3]+1,dp[i]);
    if(i%2==0) dp[i]=min(dp[i/2]+1,dp[i]);
  }

  cout << dp[n];
}