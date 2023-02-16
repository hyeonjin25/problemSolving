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
}