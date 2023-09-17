#include <bits/stdc++.h>

using namespace std;
//1000

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n; cin >>n;

  string nums[110];
  int st[110],ball[110];

  for(int i=0; i<n; i++){
    cin >> nums[i] >> st[i] >> ball[i];
  }

  int ans=0;
  for(int i=1; i<=9; i++){
    for(int j=1; j<=9; j++){
      for(int k=1; k<=9; k++){
        if(i==j||j==k||i==k) continue;
        string cur = to_string(i) + to_string(j) + to_string(k);
        int cnt=0;
        for(int h=0; h<n; h++){
          int tst=0, tball=0;
          for(int g=0; g<3; g++){
            for(int f=0; f<3; f++){
              if(g==f&&nums[h][g]==cur[f]) tst++;
              if(g!=f&&nums[h][g]==cur[f]) tball++;
            }
          }
          if(st[h]==tst&&ball[h]==tball) cnt++; 
        }
        if(cnt==n) ans++;
      }
    }
  }

  cout << ans;
}