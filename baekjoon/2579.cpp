#include <bits/stdc++.h>

using namespace std;

int dp[305][2]; // 2번째 인덱스 : 연속해서 밟은 계단의 수
int stair[305];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >>n;
  for(int i=1;i<=n;i++) cin >> stair[i];

  dp[1][1]=stair[1]; dp[1][2]=0;
  dp[2][1]=stair[2]; dp[2][2]=stair[1]+stair[2];
  for(int i=3;i<=n;i++)
  {
    dp[i][1]=max(dp[i-2][1], dp[i-2][2])+stair[i];
    dp[i][2]=dp[i-1][1]+stair[i];
  }

  cout << max(dp[n][1],dp[n][2]);
}