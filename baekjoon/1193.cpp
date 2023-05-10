#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  int x,y;
  int i=1;
  int s=1;
  while(i<n){
    s++;
    i+=s;
  }

  if(s%2==1) {
    x=1, y=s;
    x+=i-n;
    y-=i-n;
  }
  else {
    x=s, y=1;
    x-=i-n;
    y+=i-n;
  }

  cout << x << '/' << y;
}