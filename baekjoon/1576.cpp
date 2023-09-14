#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  
  int a,b,c; cin >> a >> b >> c;
  int year=1;
  while(1){
    if((year-a)%15==0&&(year-b)%28==0&&(year-c)%19==0){
      cout << year;
      return 0;
    }
    year++;
  }
}