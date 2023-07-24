#include<iostream>
using namespace std;

// 정의 : dp[i][j] : i ~ j까지 합치는데 드는 최소 비용
// 초기값 : dp[i][i] : 0
// 점화식 : 
// dp[i][j] = min(
// dp[i][i] + dp[i+1][j]
// ...
// dp[i][j-1] + dp[j][j])
// + (i+ i+1 + ... j)

int dp[505][505];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int T; cin >> T;

  while(T--){
    int k; cin >> k;
    int arr[505]; 

      for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
          if(i==j) dp[i][j]=0;
          else dp[i][j] = 1e9;
        }
      }


    for(int i=1; i<=k; i++){
      cin >> arr[i];
    }

    for(int h=2; h<=k; h++){
      for(int i=1; i<=k-h+1; i++){
        int j = i+h-1;
        for(int x=0; x<h; x++){
          dp[i][j] = min(dp[i][j], dp[i][i+x]+dp[i+x+1][j]);
        }
        for(int x=i; x<=j; x++){
          dp[i][j] += arr[x];
        }
      }
    }

    cout << dp[1][k]<<'\n';
  }
}