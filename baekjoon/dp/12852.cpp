#include<bits/stdc++.h>

using namespace std;

// 정의 : dp[i] -> i를 1로 만드는 방법의 최솟값
// 점화식 : dp[i] = min(dp[i-1], (i%3==0 && dp[i/3]), (i%2==0 && dp[i/2])) + 1
// 초깃값 : dp[1] = 1;

int dp[1000005];
int pre[1000005];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  if(n==1) {
    cout << 0 << '\n' << 1; 
    return 0;
  }

  dp[1]=0; 
  for(int i=2; i<=n; i++){
    int mn = dp[i-1]+1;
    pre[i] = i-1;
    if(i%3 == 0 && mn>dp[i/3]+1) {
      mn =  dp[i/3]+1;
      pre[i] = i/3;
    }
    if(i%2 == 0 && mn>dp[i/2]+1) {
      mn =  dp[i/2]+1;
      pre[i] = i/2;
    }
    dp[i] = mn;
  }

  cout << dp[n] << '\n';

  cout << n << ' ';
  int i = n;
  while(1){
    cout << pre[i] << ' ';
    if(pre[i]==1) break;
    i = pre[i];
  }
}