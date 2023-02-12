#include <bits/stdc++.h>

using namespace std;

long long a,b; 
bool flag=0;
int res=1e9;

void func(long long cur, int count){
  if(cur>b) return;
  if(cur==b) {
    res=min(res,count);
    flag=1;
    return;
  }
  func(cur*2, count+1);
  func(cur*10+1, count+1);
}

int main()
{
  cin >> a>>b;
  
  func(a,0);

  if(!flag) cout << -1;
  else cout << res+1;
}