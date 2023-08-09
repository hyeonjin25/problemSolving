#include<bits/stdc++.h>

using namespace std;

// 정의: dp[i] -> i로 끝나는 구간들의 최대 연속합
// 점화식: dp[i] = max(dp[i], dp[i-1] + s[i])
// 초깃값: dp[1] = s[1]

int dp[100005];
int arr[100005];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >>n;
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }

  dp[1] = arr[1];

  for(int i=2; i<=n; i++){
    dp[i] = max(arr[i], dp[i-1] + arr[i]);
  }

  int mx=-1e9;
  for(int i=1; i<=n; i++){
    mx = max(mx, dp[i]);
  }

  cout << mx;

}