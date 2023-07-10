#include <bits/stdc++.h>
using namespace std;

// 정의 : dp[i]는 i번째 피보나치 수열의 값
// 초기값 : dp[1]=1, dp[2]=1
// 점화식 : dp[i] = dp[i-1]+dp[i-2]

int main() {

    int n; cin >> n;
    int dp[50];

    dp[1]=1, dp[2]=1;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    cout << dp[n];

    return 0;
}