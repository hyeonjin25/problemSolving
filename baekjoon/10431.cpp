#include <bits/stdc++.h>

using namespace std;

//19*20/2*1000

int height[30];
int line[30];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
#if TEST
  freopen("/Users/shj41/programming/problemSolving/input.txt", "r", stdin);
#endif

  int T; cin >>T;

  int turn;
  while(T--){
    cin >> turn;
    for(int i=0; i<20; i++) cin >> height[i];
    
    int res=0;
    for(int i=1; i<20; i++){
      for(int j=0; j<i; j++){
        if(height[j]>height[i]) res++;
      }
    }
    cout << turn << ' ' << res << '\n';
  }
}