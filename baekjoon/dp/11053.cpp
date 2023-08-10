#include<iostream>
using namespace std;

// 정의 : dp[i] -> i번째 까지 수열의 부분수열 중 가장 긴 길이
// 점화식 : dp[i] = max(dp[1]+1, ... , dp[i-1]+1)
// 초깃값 : dp[1] = 1

int dp[1005];
int arr[1005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin>>n;

  for(int i=1; i<=n; i++){
    cin >> arr[i];
    dp[i] = 1;
  }

  for(int i=2; i<=n; i++){
    for(int j=1; j<i; j++){
      if(arr[j]<arr[i]) dp[i] = max(dp[i], dp[j] + 1);
    }
  }

  int mx = 0;
  for(int i=1; i<=n; i++){
    mx = max(mx, dp[i]);
  }
  cout << mx;
}