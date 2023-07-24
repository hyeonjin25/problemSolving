#include <bits/stdc++.h>

using namespace std;



int main(){
  ios::sync_with_stdio(0); cin.tie(0);
              
  vector<int> nums = {0, 0, 1, 7, 4, 2, 0, 8}; //2~7로 각각 만들 수 있는 가장 작은 수
  int T;
  cin >> T;

   // 최솟값
   vector<long long> dp(105, 1e9);
   for (int i = 2; i < 8; i++) {
		  dp[i] = nums[i];
	  }
    dp[1] = 1e9;
    dp[6] = 6;
    dp[8] = 10;

   // dp[n] = 성냥으로 구성 가능한 최솟값
   for(int i=8; i<=100; i++){
      for(int j=2; j<=7; j++){
        dp[i] = min(dp[i] , dp[i-j]*10 + nums[j]);
      }
   }

  while(T--){
    int n;
    string big="";
    cin >>n;
    
    // 최댓값
    int temp=n;
    if(n%2==1) {
      big='7';
      temp=n-3;
    }
    for(int i=0; i<temp/2; i++){
      big+='1';
    }

    cout << dp[n] <<' '<<big<<'\n';
  }
}