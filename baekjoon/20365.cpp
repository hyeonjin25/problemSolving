#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n; cin >> n;
  string str; cin >> str;

  int b=0; int r=0;
  for(int i=0; i<str.size(); i++){
    if(i!=0&&str[i-1]==str[i]) continue;
    if(str[i]=='B') b++;
    else r++;
  }
  if(b>r) cout << 1+r;
  else cout << 1+b;
}